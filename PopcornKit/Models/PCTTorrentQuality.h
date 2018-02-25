//
//  PCTTorrentQuality.h
//  PopcornKit
//
//  Copyright © 2018 Mark Bourke.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE
//

#import <Foundation/NSString.h>

/**
 The resolution of the torrent's video.
 */
typedef NSString *PCTTorrentQuality NS_EXTENSIBLE_STRING_ENUM NS_SWIFT_NAME(TorrentQuality);

/** A 1920*1080 torrent. */
extern PCTTorrentQuality const PCTTorrentQuality1080p;

/** A 1280*720 torrent. */
extern PCTTorrentQuality const PCTTorrentQuality720p;

/** A 853*480 torrent. */
extern PCTTorrentQuality const PCTTorrentQuality480p;

/** An torrent of unknown resolution. */
extern PCTTorrentQuality const PCTTorrentQualityUnknown;
