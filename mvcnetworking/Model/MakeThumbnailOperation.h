/*
    File:       MakeThumbnailOperation.h

    Contains:   An NSOperation subclass that creates a thumbnail from image data.

    Written by: DTS

    Copyright:  Copyright (c) 2010 Apple Inc. All Rights Reserved.

*/

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

@interface MakeThumbnailOperation : NSOperation
{
    NSData *        _imageData;
    NSString *      _MIMEType;
    CGFloat         _thumbnailSize;
    CGImageRef      _thumbnail;
}

- (id)initWithImageData:(NSData *)imageData MIMEType:(NSString *)MIMEType;
    // Configures the operation to create a thumbnail based on the specified data, 
    // which must be of type "image/jpeg" or "image/png".

// properties specified at init time

@property (copy,   readonly ) NSData *      imageData;
@property (copy,   readonly ) NSString *    MIMEType;

// properties that can be changed before starting the operation

@property (assign, readwrite) CGFloat       thumbnailSize;      // defaults to 32.0f

// properties that are valid after the operation is finished

// thumbnail must be a CGImage rather than a UIImage because I want the code to run on 
// iOS 3, and UIKit is completely thread unsafe on iOS 3 (as opposed to mostly thread 
// unsafe on iOS 4).

@property (assign, readonly ) CGImageRef    thumbnail;

@end
