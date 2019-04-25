// Generated by BUCKLESCRIPT VERSION 5.0.2, PLEASE EDIT WITH CARE
'use strict';


var operators = (/([\+\-\*\/])/);

var mult_or_div = (/[\*\/]/);

var add_or_sub = (/([\+\-])/);

var number = "(\\d\\.?\\d*|\\.\\d+)";

var division_group = new RegExp("" + (String(number) + ("(\\/)" + (String(number) + ""))));

var first_mult_or_div_group = new RegExp("" + (String(number) + ("" + (String("([\\*\\/])") + ("" + (String(number) + ""))))));

var first_add_or_sub_group = new RegExp("" + (String(number) + ("" + (String("([\\+\\-])") + ("" + (String(number) + ""))))));

var has_number = new RegExp(number);

exports.operators = operators;
exports.mult_or_div = mult_or_div;
exports.add_or_sub = add_or_sub;
exports.first_mult_or_div_group = first_mult_or_div_group;
exports.first_add_or_sub_group = first_add_or_sub_group;
exports.has_number = has_number;
exports.division_group = division_group;
/* operators Not a pure module */
