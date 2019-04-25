type keyType = {
  display: string,
  name: string,
};

let operators = [ 
  { display: "+", name: "plus"}, 
  { display: "-", name: "minus"}, 
  { display: "*", name: "multiply" }, 
  { display: "/", name: "divide" }
];

[@react.component]
let make = (~handleClick) => {
  <>
    {
      List.map(op => 
        <Button key=op.name handleClick={() => handleClick(op.display)}>
          {op.display |> React.string}
        </Button>, 
      operators) 
        |> Array.of_list
        |> React.array
    }
  </>
};
