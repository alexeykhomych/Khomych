//
//  AKIAutoreleasingPoolPrivate.h
//  AKIHuman
//
//  Created by Alexey Khomych on 02.06.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#ifndef AKIAutoreleasingPoolPrivate_h
#define AKIAutoreleasingPoolPrivate_h


typedef AKIAutoreleasingPoolStackContext AKIAutoreleasingPoolStackContext;
struct AKIAutoreleasingPoolStackContext {
    IDPAutoreleasingStack *stack;
    IDPAutoreleasingStack *previousStack;
};

#endif /* AKIAutoreleasingPoolPrivate_h */
