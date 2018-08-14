# PopcornKit
Objective-C wrapper for the PopcornTime API

[![Travis](https://travis-ci.org/mourke/PopcornKit.svg?branch=master)](https://travis-ci.org/mourke/PopcornKit)
[![Carthage compatible](https://img.shields.io/badge/Carthage-compatible-4BC51D.svg?style=flat)](#installation-with-carthage) [![CocoaPods compatible](https://img.shields.io/cocoapods/v/PopcornKit.svg)](#installation-with-cocoapods) ![Swift 4.0.x](https://img.shields.io/badge/Swift-4.0.x-orange.svg) ![Platforms](https://img.shields.io/badge/platform-iOS%20%7C%20macOS%20%7C%20tvOS%20%7C%20watchOS-lightgrey.svg) [![License](https://img.shields.io/badge/license-MIT-414141.svg)](https://github.com/mourke/PopcornKit/blob/master/LICENSE)

## Installation with CocoaPods

Install cocoapods with the following command:

```bash
$ gem install cocoapods
```

#### Podfile

To integrate PopcornKit into your Xcode project using CocoaPods, specify it in your `Podfile`:

```ruby
source 'https://github.com/CocoaPods/Specs.git'
platform :ios, '8.0'

target 'TargetName' do
pod 'PopcornKit', '~> 1.0.1'
end
```

Then, run the following command:

```bash
$ pod install
```

## Installation with Carthage

Install Carthage with [Homebrew](http://brew.sh/) using the following command:

```bash
$ brew update
$ brew install carthage
```

#### Cartfile

To integrate PopcornKit into your Xcode project using Carthage, specify it in your `Cartfile`:

```ogdl
github "mourke/PopcornKit"  ~> 1.0.1
```

Run `carthage` to build the framework and drag the built `PopcornKit.framework` into your Xcode project.

## License

PopcornKit is released under the MIT license. See [LICENSE](https://github.com/mourke/PopcornKit/blob/master/LICENSE) for details.
