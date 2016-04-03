//
//  Buffer.swift
//  LzmaSDK-ObjC
//
//  Created by Resident evil on 03/04/16.
//  Copyright © 2016 olehkulykov. All rights reserved.
//

import XCTest

class Buffer: XCTestCase {
    
    override func setUp() {
        super.setUp()
        // Put setup code here. This method is called before the invocation of each test method in the class.
    }
    
    override func tearDown() {
        // Put teardown code here. This method is called after the invocation of each test method in the class.
        super.tearDown()
    }
    
    func testCompressDecompress() {
		let path = self.pathForTestFile("lzma.7z")

		let src1 = NSData(contentsOfFile: path)
		XCTAssertNotNil(src1)

		let dst1 = LzmaSDKObjCBufferCompressLZMA2(src1!, 1)
		XCTAssertNotNil(dst1)

		let dst2 = LzmaSDKObjCBufferDecompressLZMA2(dst1!)
		XCTAssertNotNil(dst2)

		XCTAssertTrue(dst2!.isEqualToData(src1!))
    }
    
    func testPerformanceExample() {
        // This is an example of a performance test case.
        self.measureBlock {
            // Put the code you want to measure the time of here.
        }
    }
    
}
