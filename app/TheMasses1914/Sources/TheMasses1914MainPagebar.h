//
//	TheMasses1914MainPagebar.h
//	TheMasses1914 v2.8.6
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

#import "TheMasses1914ThumbView.h"

@class TheMasses1914MainPagebar;
@class TheMasses1914TrackControl;
@class TheMasses1914PagebarThumb;
@class TheMasses1914Document;

@protocol TheMasses1914MainPagebarDelegate <NSObject>

@required // Delegate protocols

- (void)pagebar:(TheMasses1914MainPagebar *)pagebar gotoPage:(NSInteger)page;

@end

@interface TheMasses1914MainPagebar : UIView

@property (nonatomic, weak, readwrite) id <TheMasses1914MainPagebarDelegate> delegate;

- (instancetype)initWithFrame:(CGRect)frame document:(TheMasses1914Document *)object;

- (void)updatePagebar;

- (void)hidePagebar;
- (void)showPagebar;

@end

#pragma mark -

//
//	TheMasses1914TrackControl class interface
//

@interface TheMasses1914TrackControl : UIControl

@property (nonatomic, assign, readonly) CGFloat value;

@end

#pragma mark -

//
//	TheMasses1914PagebarThumb class interface
//

@interface TheMasses1914PagebarThumb : TheMasses1914ThumbView

- (instancetype)initWithFrame:(CGRect)frame small:(BOOL)small;

@end

#pragma mark -

//
//	TheMasses1914PagebarShadow class interface
//

@interface TheMasses1914PagebarShadow : UIView

@end
