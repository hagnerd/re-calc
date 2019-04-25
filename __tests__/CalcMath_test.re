open Jest;
open Expect;
open! Expect.Operators;

open CalcMath;

describe("operate_f", () => {
  test("it should calculate correctly", () => {
    [operate_f("+", 1., 3.), operate_f("*", 2., 3.), operate_f("/", 10., 2.)]
      |> expect == [Ok(4.0), Ok(6.0), Ok(5.)] 
  })
  test("it should work with decimals", () => {
    let res = operate_f("+", 0.1, 0.02);

    res |> (
      fun
      | Ok(n) => n |> expect |> toBeCloseTo(0.12)
      | Err(err) => err |> expect == "cool"
      )
  })
})

describe("calculate", () => {
  test("it should work with a simple calculation", () => {
    expect(calculate(Ok("1+2"))) == Ok("3")
  })

  test("it should work with a complex calculation", () => {
    expect(calculate(Ok("1+2*3"))) == Ok("7")
  })

  test("it should work with floating point calculations", () => {
    calculate(Ok("1.2*3/1.25"))
      |> expect == Ok("2.88")
  })

  test("blah", () => calculate(Ok("0.1+1.2345"))|> expect == Ok("1.3345")) 
})
