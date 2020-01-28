[@bs.deriving jsConverter]
type size = [ | `small | `large];

[@bs.obj]
external makePropsLink:
  (
    ~url: string,
    ~cardSize: option(string)=?,
    ~maxLine: int=?,
    ~minLine: int=?,
    ~width: string=?,
    ~header: string=?,
    ~description: string=?,
    ~proxyUrl: string=?,
    ~showGraphic: bool=?,
    ~autoPlay: bool=?,
    ~defaultMedia: string=?
  ) =>
  _ =
  "";

[@bs.module "react-tiny-link"]
external reactComponent: React.component('a) = "ReactTinyLink";

[@react.component]
let make =
    (
      ~url: string,
      ~cardSize: option(size)=?,
      ~maxLine: option(int)=?,
      ~minLine: option(int)=?,
      ~width: option(string)=?,
      ~header: option(string)=?,
      ~description: option(string)=?,
      ~proxyUrl: option(string)=?,
      ~showGraphic: option(bool)=?,
      ~autoPlay: option(bool)=?,
      ~defaultMedia: option(string)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsLink(
      ~url,
      ~cardSize=Belt.Option.map(cardSize, sizeToJs),
      ~maxLine?,
      ~minLine?,
      ~width?,
      ~header?,
      ~description?,
      ~proxyUrl?,
      ~showGraphic?,
      ~autoPlay?,
      ~defaultMedia?,
    ),
  );