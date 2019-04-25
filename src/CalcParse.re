let get_first_occurence = (~pattern, ~input, ~start, ~length) =>
  Js.String.match(pattern, input)
  |> (
    fun
    | Some(res) => Array.sub(res, start, length)
    | None => [||]
  );

let get_first_mult_or_div = input => {
  let res =
    get_first_occurence(
      ~pattern=CalcRegex.first_mult_or_div_group,
      ~input,
      ~start=1,
      ~length=3,
    );
  let operator = res[1];
  let num1 = res[0];
  let num2 = res[2];

  (operator, num1, num2);
};

let get_first_add_or_sub = input => {
  let res =
    get_first_occurence(
      ~pattern=CalcRegex.first_add_or_sub_group,
      ~input,
      ~start=1,
      ~length=3,
    );

  let operator = res[1];
  let num1 = res[0];
  let num2 = res[2];

  (operator, num1, num2);
};

let construct_replacer = (~operator, ~n1, ~n2) => {
  Js.Re.fromString({j|$n1\\$operator$n2|j})
}

let has_operator = input => {
  Js.Re.test_(CalcRegex.operators, input)
}

let has_mult_or_div = input => {
  Js.Re.test_(CalcRegex.mult_or_div, input)
}

let has_add_or_sub = input => {
  Js.Re.test_(CalcRegex.add_or_sub, input)
}

let format_result = input => {
  let is_whole_num = mod_float(input, 1.0) == 0.0;

  switch(is_whole_num) {
    | true => input->Js.Float.toString
    | false => input->Js.Float.toPrecision
  }

}

let has_div_by_zero = input => {
  let result = Js.String.match(CalcRegex.division_group, input)
    |> (
      fun
      | Some(res) => res
      | None => [||]
      );

  let denominator = result[3];

  denominator->float_of_string == 0.0
}
