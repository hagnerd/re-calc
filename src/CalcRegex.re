let operators = [%bs.re "/([\\+\\-\\*\\/])/"];
let mult_or_div = [%bs.re "/[\\*\\/]/"];
let add_or_sub = [%bs.re "/([\\+\\-])/"];

let number = "(\\d\\.?\\d*|\\.\\d+)";
let multiplication_or_division = "([\\*\\/])";
let addition_or_subtraction = "([\\+\\-])";

let division_group = Js.Re.fromString({j|$number(\\/)$number|j});

let first_mult_or_div_group =
Js.Re.fromString({j|$number$multiplication_or_division$number|j});

let first_add_or_sub_group =
Js.Re.fromString({j|$number$addition_or_subtraction$number|j});

let has_number = Js.Re.fromString(number);
