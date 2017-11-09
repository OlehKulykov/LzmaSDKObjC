// swift-tools-version:4.0
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let packages = Package(
    name: "LzmaSDKObjC",
    products: [
        .library(
            name: "LzmaSDKObjC",
            targets: ["LzmaSDKObjC"]),

    ],
    targets: [
        .target(
            name: "LzmaSDKObjC",
            path:".",
            sources: ["src", "lmza"],
            publicHeadersPath: "src")
    ]
)
