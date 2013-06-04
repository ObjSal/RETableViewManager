//
// RETableViewSection.h
// RETableViewManager
//
// Copyright (c) 2013 Roman Efimov (https://github.com/romaonthego)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#import <Foundation/Foundation.h>

@class RETableViewManager;

/**
 Table view section.
 */
@interface RETableViewSection : NSObject

/**
 An array of section items (rows).
 */
@property (strong, readwrite, nonatomic) NSMutableArray *items;

/**
 The title of the header of the specified section of the table view
 */
@property (copy, readwrite, nonatomic) NSString *headerTitle;

/**
 The title of the footer of the specified section of the table view
 */
@property (copy, readwrite, nonatomic) NSString *footerTitle;

/**
 A view object to display in the header of the specified section of the table view.
 */
@property (strong, readwrite, nonatomic) UIView *headerView;

/**
 A view object to display in the footer of the specified section of the table view.
 */
@property (strong, readwrite, nonatomic) UIView *footerView;

@property (weak, readwrite, nonatomic) RETableViewManager *tableViewManager;

/**
 Section index in UITableView.
 */
@property (assign, readonly, nonatomic) NSUInteger index;

///-----------------------------
/// @name Creating and Initializing a RETableViewSection
///-----------------------------

/**
 Creates and returns a new section.
 @return A new section.
 */
+ (id)section;

/**
 Creates and returns a new section with predefined header title.
 @param headerTitle A header title.
 @return A new section with defined header title.
 */
+ (id)sectionWithHeaderTitle:(NSString *)headerTitle;

/**
 Creates and returns a new section with predefined header and footer titles.
 @param headerTitle A header title.
 @param footerTitle A footer title.
 @return A new section with header and footer titles.
 */
+ (id)sectionWithHeaderTitle:(NSString *)headerTitle footerTitle:(NSString *)footerTitle;

/**
 Creates and returns a new section containing a header view.
 @param headerView A header view.
 @return A new section containing a header view.
 */
+ (id)sectionWithHeaderView:(UIView *)headerView;

/**
 Creates and returns a new section containing header and footer views.
 @param headerView A header view.
 @param footerView A footer view.
 @return A new section containing header and footer views.
 */
+ (id)sectionWithHeaderView:(UIView *)headerView footerView:(UIView *)footerView;

/**
 Initializes a newly allocated section and sets header title.
 @param headerTitle A header title.
 @return A new section initialized with a header title. 
 */
- (id)initWithHeaderTitle:(NSString *)headerTitle;

/**
 Initializes a newly allocated section with header and footer titles.
 @param headerTitle A header title.
 @param footerTitle A footer title.
 @return A new section initialized with header and footer titles.
 */
- (id)initWithHeaderTitle:(NSString *)headerTitle footerTitle:(NSString *)footerTitle;

/**
 Initializes a newly allocated section containing a header view.
 @param headerView A header view.
 @return A new section initialized containing a header view.
 */
- (id)initWithHeaderView:(UIView *)headerView;

/**
 Initializes a newly allocated section containing header and footer views.
 @param headerView A header view.
 @param footerView A footer view.
 @return A new section initialized with header and footer views.
 */
- (id)initWithHeaderView:(UIView *)headerView footerView:(UIView *)footerView;

///-----------------------------
/// @name Adding Items
///-----------------------------

/**
 Inserts a given item at the end of the <items> array.
 @param item The item to add to the end of the <items> array's content. This value must not be `nil`.
 @return The item.
 */
- (void)addItem:(id)item;
- (void)addItemsFromArray:(NSArray *)array;
- (void)insertItem:(id)item atIndex:(NSUInteger)index;
- (void)insertItems:(NSArray *)items atIndexes:(NSIndexSet *)indexes;

///-----------------------------
/// @name Removing Items
///-----------------------------

- (void)removeItem:(id)item;
- (void)removeAllItems;
- (void)removeItemIdenticalTo:(id)item inRange:(NSRange)range;
- (void)removeItemIdenticalTo:(id)item;
- (void)removeItemsInArray:(NSArray *)otherArray;
- (void)removeItemsInRange:(NSRange)range;
- (void)removeItem:(id)item inRange:(NSRange)range;
- (void)removeLastItem;
- (void)removeItemAtIndex:(NSUInteger)index;
- (void)removeItemsAtIndexes:(NSIndexSet *)indexes;

///-----------------------------
/// @name Replacing Items
///-----------------------------

- (void)replaceItemAtIndex:(NSUInteger)index withItem:(id)item;
- (void)replaceItemsWithItemsFromArray:(NSArray *)otherArray;
- (void)replaceItemsAtIndexes:(NSIndexSet *)indexes withItems:(NSArray *)items;
- (void)replaceItemsInRange:(NSRange)range withItemsFromArray:(NSArray *)otherArray range:(NSRange)otherRange;
- (void)replaceItemsInRange:(NSRange)range withObjectsFromArray:(NSArray *)otherArray;

///-----------------------------
/// @name Rearranging Content
///-----------------------------

- (void)exchangeObjectAtIndex:(NSUInteger)idx1 withObjectAtIndex:(NSUInteger)idx2;
- (void)sortItemsUsingFunction:(NSInteger (*)(id, id, void *))compare context:(void *)context;
- (void)sortItemsUsingSelector:(SEL)comparator;

@end