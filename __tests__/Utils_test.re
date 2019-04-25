open Jest;
open Expect;
open! Expect.Operators;

open Utils;

describe("isNum", () => {
  test("it should return true when a number is given", () => {
    [
      isNumKey("0"),
      isNumKey("1"),
      isNumKey("2"),
      isNumKey("3"),
      isNumKey("4"),
      isNumKey("5"),
      isNumKey("6"),
      isNumKey("7"),
      isNumKey("8"),
      isNumKey("9"),
    ] |> expect == [
        true, 
        true, 
        true, 
        true, 
        true, 
        true, 
        true, 
        true, 
        true, 
        true, 
      ]
  })

  test("it should return false when not given a number", () => {
    [isNumKey("f"), isNumKey("*")]
      |> expect == [false, false]
  })
});

describe("isOpKey", () => {
  test("it should return true when an operator key is entered", () => {
    [
      isOpKey("+"),
      isOpKey("-"),
      isOpKey("*"),
      isOpKey("/"),
    ]
      |> expect == [true, true, true, true]
  })

  test(
  "it should return false when anything besides an operator key is passing in", 
  () => {
         [
           isOpKey("1"),
           isOpKey("f"),
         ]
           |> expect == [false, false]
       })
})

describe("getLastNum", () => {
  test("it returns an empty string when", () => {
    getLastNum("")
      |> expect == ""
  })
  test("it should return the last number", () => {
    getLastNum("10+2")
      |> expect == "2"
  })
  test("it should return empty string when not digit", () => {
    getLastNum("abc+def")
      |> expect == ""
  })
})

describe("lastGroupIsOpKey", () => {
  test("it should return true when the last grouping is an operator", () => {
    lastGroupIsOpKey("1+2*")
      |> expect == true
  })
  test("it should return false when the last group is not an operator", () => {
    lastGroupIsOpKey("1+2*4")
      |> expect == false
  })
})

