type result('a, 'b) =
  | Ok('a)
  | Err('b);

let operate_f = (operator, n1, n2) =>
  switch (operator) {
  | "*" => Ok(n1 *. n2)
  | "/" when n2 == 0.0 => Err("Cannot divide by zero")
  | "/" => Ok(n1 /. n2)
  | "+" => Ok(n1 +. n2)
  | "-" => Ok(n1 -. n2)
  | _ => Err("Cannot divid by zero")
  };

let calc_once = (input, ~regex) => {
  let (operator, n1, n2) = regex(input);
  let toReplace = CalcParse.construct_replacer(~operator, ~n1, ~n2);
  let result: result(float, string) =
    operate_f(operator, n1->float_of_string, n2->float_of_string);
  switch (result) {
  | Ok(res) =>
    let res = res->CalcParse.format_result;
    let new_input = Js.String.replaceByRe(toReplace, res, input);

    Ok(new_input);
  | Err(err) => Err(err)
  };
};

let rec calculate = input =>
  switch (input) {
  | Ok(input) =>
    switch (input) {
    | input
        when
          CalcParse.has_operator(input) && CalcParse.has_mult_or_div(input) =>
      let res: result(string, string) =
        calc_once(input, ~regex=CalcParse.get_first_mult_or_div);

      switch (res) {
      | Ok(new_input) => calculate(Ok(new_input))
      | Err(err) => calculate(Err(err))
      };

    | input
        when CalcParse.has_operator(input) && CalcParse.has_add_or_sub(input) =>
      let res: result(string, string) =
        calc_once(input, ~regex=CalcParse.get_first_add_or_sub);

      switch (res) {
      | Ok(new_input) => calculate(Ok(new_input))
      | Err(err) => calculate(Err(err))
      };
    | input => Ok(input)
    }
  | Err(err) => Err(err)
  };
