# use-mounted-hook-demo

## Run Project

```sh
npm install
npm start
# in another tab
npm run webpack
```

## TakeAways

### castToBool

There must be a way to use the `React.Ref.t(bool)` result as a bool. Right now it throws error that `isMounted` is of type `React.Ref.t(bool)` when looking for `bool`. I got around it for now with:

```reason
external castToBool: 'a => bool = "%identity";
```

### React.useState

Using untyped state like this:

```reason
let (data, setData) = React.useState(() => None);
```

Gets you a type for `data` of `option(unit)` so `None` is also `option(unit)`.

This is apparently satisfied by whatever you pass to `setData`.
