[@react.component]
let make = (~handleClick, ~children) => {

  let internalClick = _e => {
    handleClick();    
  };

  <button onClick={internalClick}>children</button>
};
