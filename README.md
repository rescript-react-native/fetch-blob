# `@reason-react-native/fetch-blob`

[![Build Status](https://github.com/reason-react-native/fetch-blob/workflows/Build/badge.svg)](https://github.com/reason-react-native/fetch-blob/actions)
[![Version](https://img.shields.io/npm/v/@reason-react-native/fetch-blob.svg)](https://www.npmjs.com/@reason-react-native/fetch-blob)
[![Chat](https://img.shields.io/discord/235176658175262720.svg?logo=discord&colorb=blue)](https://reasonml-community.github.io/reason-react-native/discord/)

[ReasonML](https://reasonml.github.io) /
[BuckleScript](https://bucklescript.github.io) bindings for
[`rn-fetch-blob`](https://github.com/joltup/rn-fetch-blob).

Exposed as `ReactNativeFetchBlob` module.

`@reason-react-native/fetch-blob` X.y._ means it's compatible with
`rn-fetch-blob` X.y._

## Installation

When [`rn-fetch-blob`](`https://github.com/joltup/rn-fetch-blob`) is properly
installed & configured by following their installation instructions, you can
install the bindings:

```console
npm install @reason-react-native/fetch-blob
# or
yarn add @reason-react-native/fetch-blob
```

`@reason-react-native/fetch-blob` should be added to `bs-dependencies` in your
`bsconfig.json`. Something like

```diff
{
  //...
  "bs-dependencies": [
    "reason-react",
    "reason-react-native",
    // ...
+    "@reason-react-native/fetch-blob"
  ],
  //...
}
```

## Usage

### Types

#### `ReactNativeFetchBlob.t`

...

### Methods

#### `ReactNativeFetchBlob.method`

...

---

## Changelog

Check the [changelog](./CHANGELOG.md) for more informations about recent
releases.

## Contribute

Read the [contribution guidelines](./CONTRIBUTING.md) before contributing.

## Code of Conduct

We want this community to be friendly and respectful to each other. Please read
[our full code of conduct](./CODE_OF_CONDUCT.md) so that you can understand what
actions will and will not be tolerated.
