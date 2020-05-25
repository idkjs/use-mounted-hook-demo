let useIsMounted = () => {
  let ref = React.useRef(false);

  React.useEffect0(() => {
    ref->React.Ref.setCurrent(true);
    Some(() => ref->React.Ref.setCurrent(false));
  });
  ref;
};
