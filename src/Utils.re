[@bs.val]
external addKeyboardListener: (string, ReactEvent.Keyboard.t => unit) => unit =
  "addEventListener";

[@bs.val]
external removeKeyboardListener:
  (string, ReactEvent.Keyboard.t => unit) => unit =
  "removeEventListener";

let isNumKey = key =>
switch(key) {
  | "0"
  | "1"
  | "2"
  | "3"
  | "4"
  | "5"
  | "6"
  | "7"
  | "8"
  | "9" => true
  | _ => false
};

let isOpKey = key =>
switch(key) {
  | "+"
  | "-"
  | "*"
  | "/" => true
  | _ => false
};

let getLastNum = input => {
  let nums = Js.String.splitByRe(CalcRegex.operators, input);
  if (Array.length(nums) > 0) {
    switch(Array.get(nums, Array.length(nums) - 1 )) {
      | Some(num) when !Js.Re.test_(CalcRegex.has_number, num) => "" 
      | Some(num) => num
      | None => ""
    }
  } else {
    ""
  }
}

let lastGroupIsOpKey = input => {
  let chars = Js.String.split("", input)
    |> Array.to_list
    |> List.filter(a => a != "");

    let last = List.nth(chars, List.length(chars) - 1);
    isOpKey(last)
}
