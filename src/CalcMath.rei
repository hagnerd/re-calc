type result('a, 'b) = 
  | Ok('a)
  | Err('b);

let operate_f: (string, float, float) => result(float, string);

let calculate: result(string, string) => result(string, string);

let calc_once:
  (
    string,
    ~regex: string => (string, string, string),
  ) =>
  result(string, string);
