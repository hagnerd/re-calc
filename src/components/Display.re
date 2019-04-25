module Style = {
  open Emotion;

  let title = [%css [
    height(`rem(2.0)),
    fontSize(`rem(2.0)),
    color(`hex("569462"))
  ]];
}

[@react.component]
let make = (~text) => <h1 className=Style.title>{text |> React.string}</h1>
