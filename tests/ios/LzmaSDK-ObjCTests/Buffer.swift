//
//  Buffer.swift
//  LzmaSDK-ObjC
//
//  Created by Resident evil on 03/04/16.
//  Copyright © 2016 olehkulykov. All rights reserved.
//

import XCTest

class Buffer: XCTestCase {

    func testCompressDecompress() {
		let path = self.pathForTestFile("lzma.7z")

		let sourceData = NSData(contentsOfFile: path)
		XCTAssertNotNil(sourceData)

		let compressedData = LzmaSDKObjCBufferCompressLZMA2(sourceData!, 1)
		XCTAssertNotNil(compressedData)

		let decompressedData = LzmaSDKObjCBufferDecompressLZMA2(compressedData!)
		XCTAssertNotNil(decompressedData)

		XCTAssertTrue(decompressedData!.isEqualToData(sourceData!))
    }
    
}
