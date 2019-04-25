open Jest;
open JestDom;
open Expect;
open ReactTestingLibrary;

let noop = () => ();

test("renders correctly", () =>  {
  let element = (
    <Button handleClick=noop>{"Submit" |> React.string}</Button>
  );

  (element |> render |> getByText(~matcher=`Str("Submit")))
  -> Some 
  |> expect
  |> toBeInTheDocument; 
});

