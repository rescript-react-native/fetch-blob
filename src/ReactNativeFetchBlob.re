type t;
[@bs.module "rn-fetch-blob"] external fetchBlob: t = "default";

module Config = {
  [@bs.deriving {abstract: light}]
  type t = {
    [@bs.optional]
    fileCache: bool,
    [@bs.optional]
    appendExt: string,
    [@bs.optional]
    path: string,
    [@bs.optional]
    key: string,
    [@bs.optional]
    timeout: int,
    [@bs.optional]
    wifiOnly: bool,
  };
};

module ResponseInfo = {
  type t;
  [@bs.get] external headers: t => Js.Dict.t(string) = "headers";
  [@bs.get] external status: t => int = "status";
};

module Response = {
  type t;
  [@bs.send] external info: t => ResponseInfo.t = "info";
  [@bs.send] external text: t => string = "text";
  [@bs.send] external json: t => Js.Json.t = "json";

  /* For file downloads */
  [@bs.send] external path: t => string = "path";
};

module Fetch = {
  type t;
  [@bs.send]
  external fetch:
    (t, ~method: string, ~url: string, ~headers: Js.t({.}), ~body: 'a) =>
    Js.Promise.t(Response.t) =
    "fetch";
};

module Fs = {
  module Stat = {
    [@bs.deriving {abstract: light}]
    type t = {
      filename: string,
      path: string,
      size: int,
      [@bs.as "type"]
      type_: string,
      lastModified: float,
    };
  };

  type dirs;

  [@bs.get] external documentDir: dirs => string = "DocumentDir";
  [@bs.get] external cacheDir: dirs => string = "CacheDir";

  /* Can be used to access files embedded on iOS apps only */
  [@bs.get] external mainBundleDir: dirs => string = "MainBundleDir";

  /* Android Only */
  [@bs.get] external dcimDir: dirs => string = "DCIMDir";
  [@bs.get] external downloadDir: dirs => string = "DownloadDir";
  [@bs.get] external musicDir: dirs => string = "MusicDir";
  [@bs.get] external pictureDir: dirs => string = "PictureDir";
  [@bs.get] external movieDir: dirs => string = "MovieDir";
  [@bs.get] external ringtoneDir: dirs => string = "RingtoneDir";
  [@bs.get] external sdCardDir: dirs => string = "SDCardDir";

  type t;

  [@bs.get] external dirs: t => dirs = "dirs";
  [@bs.send]
  external cp: (t, ~from: string, ~to_: string) => Js.Promise.t(unit) =
    "from";
  [@bs.send]
  external unlink: (t, ~path: string) => Js.Promise.t(unit) = "unlink";
  [@bs.send]
  external mkdir: (t, ~path: string) => Js.Promise.t(unit) = "mkdir";
  [@bs.send]
  external exists: (t, ~path: string) => Js.Promise.t(bool) = "exists";
  [@bs.send]
  external lstat: (t, ~path: string) => Js.Promise.t(array(Stat.t)) = "path";
  [@bs.send]
  external stat: (t, ~path: string) => Js.Promise.t(Stat.t) = "stat";
  [@bs.send]
  external readFile:
    (t, ~path: string, ~encoding: string) => Js.Promise.t(string) =
    "readFile";
  [@bs.send] external asset: (t, ~path: string) => string = "asset";
};

[@bs.send] external config: (t, Config.t) => Fetch.t = "config";
[@bs.get] external fs: t => Fs.t = "fs";

type data;

[@bs.send] external wrap: (t, ~path: string) => data = "wrap";
