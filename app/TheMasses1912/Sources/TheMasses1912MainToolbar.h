//
//	TheMasses1912MainToolbar.h
//	TheMasses1912 v2.8.6
//
//	Created by Julius Oklamcak on 2011-07-01.
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

#import "UIXToolbarView.h"

@class TheMasses1912MainToolbar;
@class TheMasses1912Document;

@protocol TheMasses1912MainToolbarDelegate <NSObject>

@required // Delegate protocols

- (void)tappedInToolbar:(TheMasses1912MainToolbar *)toolbar doneButton:(UIButton *)button;
- (void)tappedInToolbar:(TheMasses1912MainToolbar *)toolbar thumbsButton:(UIButton *)button;
- (void)tappedInToolbar:(TheMasses1912MainToolbar *)toolbar exportButton:(UIButton *)button;
- (void)tappedInToolbar:(TheMasses1912MainToolbar *)toolbar printButton:(UIButton *)button;
- (void)tappedInToolbar:(TheMasses1912MainToolbar *)toolbar emailButton:(UIButton *)button;
- (void)tappedInToolbar:(TheMasses1912MainToolbar *)toolbar markButton:(UIButton *)button;

@end

@interface TheMasses1912MainToolbar : UIXToolbarView

@property (nonatomic, weak, readwrite) id <TheMasses1912MainToolbarDelegate> delegate;

- (instancetype)initWithFrame:(CGRect)frame document:(TheMasses1912Document *)document;

- (void)setBookmarkState:(BOOL)state;

- (void)hideToolbar;
- (void)showToolbar;

@end
