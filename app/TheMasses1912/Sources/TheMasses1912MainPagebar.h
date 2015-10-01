//
//	TheMasses1912MainPagebar.h
//	TheMasses1912 v2.8.6
//
//	Created by Julius Oklamcak on 2011-09-01.
//	Copyright © 2011-2015 Julius Oklamcak. All rights reserved.
//
//	Permission is hereby granted, free of charge, to any person obtaining a copy
//	of this software and associated documentation files (the "Software"), to deal
//	in the Software without restriction, including without limitation the rights to
//	use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
//	of the Software, and to permit persons to whom the Software is furnished to
//	do so, subject to the following conditions:
//
//	The above copyright notice and this permission notice shall be included in all
//	copies or substantial portions of the Software.
//
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//	OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
//	WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
//	CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

#import <UIKit/UIKit.h>

#import "TheMasses1912ThumbView.h"

@class TheMasses1912MainPagebar;
@class TheMasses1912TrackControl;
@class TheMasses1912PagebarThumb;
@class TheMasses1912Document;

@protocol TheMasses1912MainPagebarDelegate <NSObject>

@required // Delegate protocols

- (void)pagebar:(TheMasses1912MainPagebar *)pagebar gotoPage:(NSInteger)page;

@end

@interface TheMasses1912MainPagebar : UIView

@property (nonatomic, weak, readwrite) id <TheMasses1912MainPagebarDelegate> delegate;

- (instancetype)initWithFrame:(CGRect)frame document:(TheMasses1912Document *)object;

- (void)updatePagebar;

- (void)hidePagebar;
- (void)showPagebar;

@end

#pragma mark -

//
//	TheMasses1912TrackControl class interface
//

@interface TheMasses1912TrackControl : UIControl

@property (nonatomic, assign, readonly) CGFloat value;

@end

#pragma mark -

//
//	TheMasses1912PagebarThumb class interface
//

@interface TheMasses1912PagebarThumb : TheMasses1912ThumbView

- (instancetype)initWithFrame:(CGRect)frame small:(BOOL)small;

@end

#pragma mark -

//
//	TheMasses1912PagebarShadow class interface
//

@interface TheMasses1912PagebarShadow : UIView

@end
