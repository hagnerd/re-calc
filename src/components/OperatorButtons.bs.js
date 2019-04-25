// Generated by BUCKLESCRIPT VERSION 5.0.2, PLEASE EDIT WITH CARE
'use strict';

var List = require("bs-platform/lib/js/list.js");
var $$Array = require("bs-platform/lib/js/array.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Button$ReCalc = require("./Button.bs.js");

var operators = /* :: */[
  /* record */[
    /* display */"+",
    /* name */"plus"
  ],
  /* :: */[
    /* record */[
      /* display */"-",
      /* name */"minus"
    ],
    /* :: */[
      /* record */[
        /* display */"*",
        /* name */"multiply"
      ],
      /* :: */[
        /* record */[
          /* display */"/",
          /* name */"divide"
        ],
        /* [] */0
      ]
    ]
  ]
];

function OperatorButtons(Props) {
  var handleClick = Props.handleClick;
  return React.createElement(React.Fragment, undefined, $$Array.of_list(List.map((function (op) {
                        return React.createElement(Button$ReCalc.make, {
                                    handleClick: (function (param) {
                                        return Curry._1(handleClick, op[/* display */0]);
                                      }),
                                    children: op[/* display */0],
                                    key: op[/* name */1]
                                  });
                      }), operators)));
}

var make = OperatorButtons;

exports.operators = operators;
exports.make = make;
/* react Not a pure module */