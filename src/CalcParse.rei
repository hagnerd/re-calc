let get_first_mult_or_div: string => (string, string, string);
let get_first_add_or_sub: string => (string, string, string);

let construct_replacer: (~operator: string, ~n1: string, ~n2: string) => Js_re.t;

let has_operator: string => bool;
let has_mult_or_div: string => bool;
let has_add_or_sub: string => bool;
let has_div_by_zero: string => bool;
let format_result: float => string;
