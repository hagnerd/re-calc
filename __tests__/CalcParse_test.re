open Jest;
open Expect;
open! Expect.Operators;

open CalcParse;

describe("get_first_mult_or_div", () => {
  test("it should return the first multiplication group", () => {
    get_first_mult_or_div("1+2*3/4")
      |> expect == ("*", "2", "3")
  })

  test("it should returnt the first division group", () => {
    get_first_mult_or_div("1+2/3*4")
      |> expect == ("/", "2", "3")
  })
});

describe("get_first_add_or_sub", () => {
  test("it should return the first addition group", () => {
    get_first_add_or_sub("1*2+3-4")
      |> expect == ("+", "2", "3")
  })

  test("it should return the first subtraction group", () => {
    get_first_add_or_sub("1*2-3+4")
      |> expect == ("-", "2", "3")
  })
});

describe("construct_replacer", () => {
  test("it should construct correctly", () => {
    let operator = "*";
    let n1 = "2";
    let n2 = "4";
    let replacer = construct_replacer(~operator, ~n1, ~n2);
    expect(replacer) == [%bs.re "/2\\*4/"]; 
  })
})

describe("has_operator", () => {
  test("it should return true when operator is present", () => {
    has_operator("2*3+1-2/5")
      |> expect == true
  })
  test("it should return false when operator isn't present", () => {
    has_operator("23125")
      |> expect == false
  })
})

describe("has_add_or_sub", () => {
  test("it should return true when input has + operator", () =>
       has_add_or_sub("2+3")
        |> expect == true 
  )

  test("it should return true when input has - operator", () =>
       has_add_or_sub("2-3")
        |> expect == true 
  )

  test("it should return true when input has multiple +/- operators", () =>
       has_add_or_sub("2-3+4-1")
        |> expect == true 
  )

  test("it should return false when input has no +/- operators", () =>
       has_add_or_sub("2*3/4*1")
        |> expect == false 
  )
})

describe("has_mult_or_div", () => {
  test("it should return true when * is present", () => {
    has_mult_or_div("2*3")
      |> expect == true
  })

  test("it should return true when / is present", () => {
    has_mult_or_div("2/3")
      |> expect == true
  })

  test("it should return true when * and / is present", () => {
    has_mult_or_div("2*4/3")
      |> expect == true
  })

  test("it should return false when * and / are not present", () => {
    has_mult_or_div("2+3-4")
      |> expect == false
  })
})

describe("format_result", () => {
  test("it should format number with decimal", () => {
    format_result(3.100)
      |> expect == "3.1"
  })

  test("it should format whole number", () => {
    format_result(3.0)
      |> expect == "3"
  })
})

describe("has_div_by_zero", () => {
  test("it should return true when divide by zero is present", () => {
    has_div_by_zero("1+2*3/0")
      |> expect == true
  })

  test("it should return false when divide by zero is not present", () => {
    has_div_by_zero("1/2")
      |> expect == false
  })
})

