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

class Read: XCTestCase {
    
    override func setUp() {
        super.setUp()

		let path = self.pathForTestFile(testFilePath: "lzma.7z")
		XCTAssertNotNil(path)
		XCTAssert(path.lengthOfBytes(using: String.Encoding.utf8) > 0)

		let writePath = self.tmpWritePath()
		XCTAssertNotNil(writePath)
    }

    func testExtract() {
		for file in ["lzma.7z", "lzma_aes256.7z", "lzma_aes256_encfn.7z"] {
			let reader = LzmaSDKObjCReader(fileURL: URL(string: self.pathForTestFile(testFilePath: file))!)

			reader.passwordGetter = {
				return "1234"
			}

			do {
				try reader.open()
			} catch let error as NSError {
				fatalError(error.localizedDescription)
			}

			var archiveItems = [LzmaSDKObjCItem]()
            var result = reader.iterate(handler: { (item, error) -> Bool in
				XCTAssertNil(error)
				archiveItems.append(item)
				if item.fileName == "shutuptakemoney.jpg" {
					XCTAssertTrue(item.originalSize == 33402)
					XCTAssertTrue(item.crc32 == 0x0b0646c5)
				} else if item.fileName == "SouthPark.jpg" {
					XCTAssertTrue(item.originalSize == 40782)
					XCTAssertTrue(item.crc32 == 0x1243b886)
				} else if item.fileName == "zombies.jpg" {
					XCTAssertTrue(item.originalSize == 83131)
					XCTAssertTrue(item.crc32 == 0xb5e98c78)
				}
				return true
			})
			XCTAssertTrue(result)

			let extractPath = self.tmpWritePath()

			result = reader.extract(archiveItems, toPath: extractPath, withFullPaths: false)
			XCTAssertTrue(result)

			let readed = try? FileManager.default.contentsOfDirectory(atPath: extractPath)
			XCTAssertTrue(readed!.count == archiveItems.count)

			do {
				try FileManager.default.removeItem(atPath: extractPath)
			} catch _ {

			}
		}
    }

}
