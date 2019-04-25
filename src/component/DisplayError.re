module Styles = {
  open Emotion;

  let errMsg = [%css [
    height(`rem(2.0)),
    color(`hex("ff5d3b"))
  ]];
}

[@react.component]
let make = (~error) => <h2 className=Styles.errMsg>{switch(error) {
  | Some(msg) => msg
  | None => ""
} |> React.string}</h2>
