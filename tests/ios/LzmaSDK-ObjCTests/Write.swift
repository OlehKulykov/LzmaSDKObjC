/*
*   Copyright (c) 2015 - 2016 Kulykov Oleh <info@resident.name>
*
*   Permission is hereby granted, free of charge, to any person obtaining a copy
*   of this software and associated documentation files (the "Software"), to deal
*   in the Software without restriction, including without limitation the rights
*   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*   copies of the Software, and to permit persons to whom the Software is
*   furnished to do so, subject to the following conditions:
*
*   The above copyright notice and this permission notice shall be included in
*   all copies or substantial portions of the Software.
*
*   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
*   THE SOFTWARE.
*/


import XCTest

class Write: XCTestCase {

	var writer: LzmaSDKObjCWriter?

	func testMutableItem() {
		let item = LzmaSDKObjCMutableItem()

		item.setPath("f", isDirectory: false)
		XCTAssertTrue(item.path == "f")
		XCTAssertFalse(item.isDirectory)
		XCTAssertNil(item.directoryPath)
		XCTAssertTrue(item.fileName == "f")

		item.setPath("d/f", isDirectory: false)
		XCTAssertTrue(item.path == "d/f")
		XCTAssertFalse(item.isDirectory)
		XCTAssertNotNil(item.directoryPath)
		XCTAssertTrue(item.fileName == "f")
		XCTAssertTrue(item.directoryPath == "d")

		item.setPath("d", isDirectory: true)
		XCTAssertTrue(item.path == "d")
		XCTAssertTrue(item.isDirectory)
		XCTAssertNotNil(item.directoryPath)
		XCTAssertNil(item.fileName)
		XCTAssertTrue(item.directoryPath == "d")

		item.setPath("d1/d2", isDirectory: true)
		XCTAssertTrue(item.path == "d1/d2")
		XCTAssertTrue(item.isDirectory)
		XCTAssertNotNil(item.directoryPath)
		XCTAssertNil(item.fileName)
		XCTAssertTrue(item.directoryPath == "d1/d2")

		let now = NSDate()
		item.modificationDate = now
		item.accessDate = now
		item.creationDate = now

		let mDate = item.modificationDate
		let aDate = item.accessDate
		let cDate = item.creationDate

		// compare as uints
		XCTAssertTrue(UInt(mDate!.timeIntervalSince1970) == UInt(now.timeIntervalSince1970));
		XCTAssertTrue(UInt(aDate!.timeIntervalSince1970) == UInt(now.timeIntervalSince1970));
		XCTAssertTrue(UInt(cDate!.timeIntervalSince1970) == UInt(now.timeIntervalSince1970));
	}

    func testWriteNew() {
	
    }

    func testPerformanceExample() {
        // This is an example of a performance test case.
        self.measureBlock {
            // Put the code you want to measure the time of here.
        }
    }

}

extension Write: LzmaSDKObjCWriterDelegate {
	func onLzmaSDKObjCWriter(writer: LzmaSDKObjCWriter, writeProgress progress: Float) {
		print("Progress: \(progress), \(100 * progress)%")
	}
}
