open Jest;
open Expect;
open! Expect.Operators;

describe("CalcRegex", () => {
  open CalcRegex;

  test("it should match a plus sign", () => {
    Js.Re.test_(operators, "2+3")
      |> expect == true
  })

  test("it should match a minus sign", () => {
    Js.Re.test_(operators, "2-3")
      |> expect == true
  })

  test("it should match a multiplication sign", () => {
    Js.Re.test_(operators, "2*3")
      |> expect == true
  })

  test("it should match a division sign", () => {
    Js.Re.test_(operators, "2/3")
      |> expect == true
  })

  test("it should match if any/all are present", () => {
    Js.Re.test_(operators, "2+3*1-1/2")
      |> expect == true
  })

  test("finds first multiplication", () => {
    let res = Js.String.match(first_mult_or_div_group, "1+2*3")
      |> (
        fun
        | Some(res) => Array.sub(res, 1, 3)
        | None => [||]
        );

    expect(res) == [|"2", "*", "3"|]
  })

  test("finds first division", () => {
    let res = Js.String.match(first_mult_or_div_group, "1+2/3")
      |> (
        fun
        | Some(res) => Array.sub(res, 1, 3)
        | None => [||]
        );

    expect(res) == [|"2", "/", "3"|]
  })

  test("finds first addition", () => {
    let res = Js.String.match(first_add_or_sub_group, "1*2+3")
      |> (
        fun
        | Some(res) => Array.sub(res, 1, 3)
        | None => [||]
        );

    expect(res) == [|"2", "+", "3"|]
  })

  test("finds first subtraction", () => {
    let res = Js.String.match(first_add_or_sub_group, "1*2-3")
      |> (
        fun
        | Some(res) => Array.sub(res, 1, 3)
        | None => [||]
        );

    expect(res) == [|"2", "-", "3"|]
  })

  test("it should return true when * is present", () => {
    Js.Re.test_(mult_or_div, "2*3")
      |> expect == true
  })

  test("it should return true when / is present", () => {
    Js.Re.test_(mult_or_div, "2/3")
      |> expect == true
  })

  test("it should return false when * and / are not present", () => {
    Js.Re.test_(mult_or_div, "2+3")
      |> expect == false
  })

  test("it should return true when + is present", () => {
    Js.Re.test_(add_or_sub, "2+3")
      |> expect == true
  })

  test("it should return true when - is present", () => {
    Js.Re.test_(add_or_sub, "2-3")
      |> expect == true
  })

  test("it should return false when - and + are not present", () => {
    Js.Re.test_(add_or_sub, "2*3")
      |> expect == false
  })

  test("it should return true when number precedes . in floating point number", () =>
       {
         Js.Re.test_(has_number, "3.01")
         |> expect == true
       })

  test("it should return true when no number precedes . in floating point
       number", () => {
         Js.Re.test_(has_number, ".01")
         |> expect == true
       })
  test("it should return true when no . is present", () => {
    Js.Re.test_(has_number, "103")
      |> expect == true
  })

  test("it should return true when devided by zero", () => {
    let results = Js.String.match(division_group, "12/0")
      |> (
        fun
        | Some(res) => res
        | None => [||]
        );

    let n2 = results[3] -> float_of_string;
    expect(n2) == 0.0
  })
});
