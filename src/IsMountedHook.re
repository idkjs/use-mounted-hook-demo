let useIsMounted = () => {
  let ref = React.useRef(false);

  React.useEffect0(() => {
    ref->React.Ref.setCurrent(true);
    Some(() => ref->React.Ref.setCurrent(false));
  });
  ref;
};
// module Auth = {
//   type t;
//   [@bs.module ("@aws-amplify/auth", "Auth")] external auth: t = "Auth";
// };
// module Hub = {
//   type t;
//   [@bs.module ("@aws-amplify/auth", "Hub")] external hub: t = "Hub";
// };
// module HubCapsule = {
//   /* import { HubCapsule } from '@aws-amplify/core/lib/Hub'; */
//   type t;
//   [@bs.module ("@aws-amplify/core/lib/Hub", "HubCapsule")]
//   external hub: t = "HubCapsule";
// };
// type authData = Js.Nullable.t(string);
// type authState = string;
// type state = {
//   authState,
//   authData,
// };
// let state = {authData: Js.Nullable.null, authState: ""};
// let useAuth = () => {
//   let isMounted = useIsMounted();
//   let (state, setState) =
//     React.useState(() => {authState: "loading", authData: Js.Nullable.null});

//   let handleStateChange =
//     React.useCallback(
//       (authState, authData) => {
//         if (authState === "signedOut") {
//           setState(_ => {...state, authState: "signedIn"});
//         };
//         if (isMounted) {
//           setState(prevState => {...prevState, authState, authData});
//         };
//       },
//       [|isMounted|],
//     );
//   ();
// };