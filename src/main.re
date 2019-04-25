module App = {
  type state = {
    display: string,
    error: option(string),
  };

  type action =
    | AddToDisplay(string)
    | Compute
    | ClearDisplay;

  let initialState = {display: "", error: None};

  let reducer = (state, action) =>
    switch (action) {
    | AddToDisplay(s) when s == "." && Utils.lastGroupIsOpKey(state.display) => {
        ...state,
        error: Some("Cannot make " ++ s ++ " a decimal"),
      }
    | AddToDisplay(s) when s == "." =>
      let last = Utils.getLastNum(state.display);

      if (last != "" && !Js.String.includes(".", last)) {
        {display: state.display ++ s, error: None};
      } else {
        {...state, error: Some("Number is already a decimal")};
      };
    | AddToDisplay(s) when Utils.isOpKey(s) && state.display == "" => state
    | AddToDisplay(s) when Utils.isOpKey(s) =>
      if (Utils.lastGroupIsOpKey(state.display)) {
        {...state, error: Some("Cannot have two operators in a row")};
      } else {
        {display: state.display ++ s, error: None};
      }
    | AddToDisplay(s) => {display: state.display ++ s, error: None}
    | Compute when state.display == "" => {
        ...state,
        error: Some("Nothing to
      calculate"),
      }
    | Compute when Utils.lastGroupIsOpKey(state.display) => {
        ...state,
        error: Some("Cannot compute with dangling operator"),
      }
    | Compute =>
      let result = CalcMath.calculate(Ok(state.display));

      switch (result) {
      | Ok(res) => {display: res, error: None}
      | Err(msg) => {...state, error: Some(msg)}
      };
    | ClearDisplay => {display: "", error: None}
    };

  let useListener = (event, callback) =>
    React.useEffect0(() => {
      Utils.addKeyboardListener(event, callback);
      Some(() => Utils.removeKeyboardListener(event, callback));
    });

  let listen = (dispatch, event) => {
    Js.log(ReactEvent.Keyboard.key(event));

    switch (ReactEvent.Keyboard.key(event)) {
    | x when Utils.isNumKey(x) || Utils.isOpKey(x) || x == "." =>
      dispatch(AddToDisplay(x))
    | x when x == "=" => dispatch(Compute)
    | _ => ()
    };
  };

  [@react.component]
  let make = () => {
    let (state, dispatch) = React.useReducer(reducer, initialState);
    useListener("keypress", listen(dispatch));

    <>
      <Display text={state.display} />
      <DisplayError error={state.error} />
      <NumButtons handleClick={n => dispatch(AddToDisplay(n))} />
      <OperatorButtons handleClick={op => dispatch(AddToDisplay(op))} />
      <Button handleClick={() => dispatch(ClearDisplay)}>
        {"Clear" |> React.string}
      </Button>
      <Button handleClick={() => dispatch(Compute)}>
        {"=" |> React.string}
      </Button>
    </>;
  };
};

ReactDOMRe.renderToElementWithId(<App />, "app");
