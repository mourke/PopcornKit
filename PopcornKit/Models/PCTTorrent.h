//
//  PCTTorrent.h
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

#import <Foundation/Foundation.h>
#import "PCTTorrentQuality.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(Torrent)
@interface PCTTorrent : NSObject

/** The website from which the torrent was scraped. */
@property (strong, nonatomic, readonly) NSString *provider;

/** The size of the torrent (in bytes). */
@property (nonatomic, readonly) NSUInteger size;

/** The total number of people currently downloading the torrent. */
@property (nonatomic, readonly) NSUInteger peers;

/** The total number of people currently seeding the torrent. */
@property (nonatomic, readonly) NSUInteger seeds;

/** The URL (magnet or direct link) of the torrent file. */
@property (strong, nonatomic, readonly) NSURL *URL NS_SWIFT_NAME(url);

/** The quality of the torrent. */
@property (strong, nonatomic) PCTTorrentQuality quality;

@end

NS_ASSUME_NONNULL_END
