/*     Copyright 2015-2017 Egor Yusov
 *  
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF ANY PROPRIETARY RIGHTS.
 *
 *  In no event and under no legal theory, whether in tort (including negligence), 
 *  contract, or otherwise, unless required by applicable law (such as deliberate 
 *  and grossly negligent acts) or agreed to in writing, shall any Contributor be
 *  liable for any damages, including any direct, indirect, special, incidental, 
 *  or consequential damages of any character arising as a result of this License or 
 *  out of the use or inability to use the software (including but not limited to damages 
 *  for loss of goodwill, work stoppage, computer failure or malfunction, or any and 
 *  all other commercial damages or losses), even if such Contributor has been advised 
 *  of the possibility of such damages.
 */

#pragma once

/// \file
/// Implementation of the Diligent::ObjectBase template class

#include "Object.h"
#include "RefCountedObjectImpl.h"

namespace Diligent
{


#define IMPLEMENT_QUERY_INTERFACE_BODY(InterfaceID, ParentClassName) \
{                                                               \
    if( ppInterface == nullptr )                                \
        return;                                                 \
    if( IID == InterfaceID )                                    \
    {                                                           \
        *ppInterface = this;                                    \
        (*ppInterface)->AddRef();                               \
    }                                                           \
    else                                                        \
    {                                                           \
        ParentClassName::QueryInterface( IID, ppInterface );    \
    }                                                           \
}

#define IMPLEMENT_QUERY_INTERFACE(ClassName, InterfaceID, ParentClassName) \
    void ClassName :: QueryInterface(const Diligent::INTERFACE_ID &IID, IObject **ppInterface) \
    IMPLEMENT_QUERY_INTERFACE_BODY(InterfaceID, ParentClassName)

#define IMPLEMENT_QUERY_INTERFACE_IN_PLACE(InterfaceID, ParentClassName) \
    virtual void QueryInterface(const Diligent::INTERFACE_ID &IID, IObject **ppInterface) \
    IMPLEMENT_QUERY_INTERFACE_BODY(InterfaceID, ParentClassName)


/// Template class implementing base functionality for an object
template<typename BaseInterface, typename TObjectAllocator = IMemoryAllocator>
class ObjectBase : public RefCountedObject<BaseInterface, TObjectAllocator>
{
public:
    ObjectBase(IObject *pOwner = nullptr, TObjectAllocator *pObjAllocator = nullptr) : 
        RefCountedObject<BaseInterface, TObjectAllocator>( pOwner, pObjAllocator )
    {}

    virtual void QueryInterface( const Diligent::INTERFACE_ID &IID, IObject **ppInterface )
    {
        if( ppInterface == nullptr )
            return;

        *ppInterface = nullptr;
        if( IID == Diligent::IID_Unknown )
        {
            *ppInterface = this;
            (*ppInterface)->AddRef();
        }
    }
};

}
