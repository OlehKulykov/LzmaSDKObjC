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

extension XCTestCase {

	func pathForTestFile(testFilePath: String) -> String {
		let filePath = testFilePath as NSString
		guard let
			fullPath = Bundle(for: type(of: self)).path(forResource: filePath.deletingPathExtension, ofType: filePath.pathExtension)
			else {
				fatalError("Can't read resource file full path")
		}
		return fullPath
	}

	func tmpWritePath() -> String {
		guard let
			path = NSSearchPathForDirectoriesInDomains(FileManager.SearchPathDirectory.cachesDirectory, FileManager.SearchPathDomainMask.userDomainMask, true).first
			else {
				fatalError("Can't get cache path")
		}
		let	fullPath = path.appendingFormat("/tmp_test")

		do {
			try FileManager.default.removeItem(atPath: fullPath)
		} catch _ {

		}

		do {
			try FileManager.default.createDirectory(atPath: fullPath, withIntermediateDirectories: true, attributes: nil)
		} catch _ {
			fatalError("Can't create path")
		}
		return fullPath
	}
}
