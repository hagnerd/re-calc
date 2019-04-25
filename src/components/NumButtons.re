  let nums = ["1", "2", "3", "4", "5", "6", "7", "8", "9", "0"];

  [@react.component]
    let make = (~handleClick) => {
      <>
      {List.map(n => <Button key=n handleClick={() => handleClick(n)}>{n |>
        React.string}
        </Button>, nums)
        |> Array.of_list
        |> React.array }
      </>
    }
