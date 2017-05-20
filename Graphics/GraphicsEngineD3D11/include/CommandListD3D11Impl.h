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
/// Declaration of Diligent::CommandListD3D11Impl class

#include "RenderDeviceD3D11.h"
#include "CommandListBase.h"

namespace Diligent
{

class FixedBlockMemoryAllocator;

/// Implementation of the Diligent::ICommandListD3D11 interface
class CommandListD3D11Impl : public CommandListBase<ICommandList, FixedBlockMemoryAllocator>
{
public:
    typedef CommandListBase<ICommandList, FixedBlockMemoryAllocator> TCommandListBase;
    CommandListD3D11Impl(FixedBlockMemoryAllocator &CommandListObjMemAllocator,
                         IRenderDevice *pDevice, 
                         ID3D11CommandList *pd3d11CommandList);
    ~CommandListD3D11Impl();

    ID3D11CommandList *GetD3D11CommandList(){ return m_pd3d11CommandList; }

private:
    CComPtr<ID3D11CommandList> m_pd3d11CommandList; ///< D3D11 CommandList object
};

}
