let handleClick = _event => Js.log("clicked!");
exception UnhandledPromise;

let result = (): Js.Promise.t('a) =>
  Js.Promise.(
    Axios.get("http://hn.algolia.com/api/v1/search?query=redux")
    |> then_(response => response##data |> resolve)
    |> catch(error => resolve(Js.log(error)))
  );
external castToBool: 'a => bool = "%identity";
[@react.component]
let make = () => {
  let isMounted = IsMountedHook.useIsMounted();
  let (data, setData) = React.useState(() => None);
  let handleClick = _event => Js.log(data);
  React.useEffect1(
    () => {
      let current = isMounted->castToBool;
      // let current = false;
      Js.log2("current",current);
      // let fetchData = () => {
          let _ =Js.Promise.(
            result()
            |> then_(result =>
                 (
                   if (current) {
                     setData(_ => Some(result));
                   }
                 )
                 |> resolve
               )
            |> catch(e => {
                 Js.log(e);
                 raise(UnhandledPromise);
               })
          );
      // };

      // let _ = fetchData();
      None;
    },
    [|isMounted|],
  );

  let isData = data->Belt.Option.isSome;

  isData
    ? <button onClick=handleClick> "log data"->React.string </button>
    : {
      "no data"->React.string;
    };
};