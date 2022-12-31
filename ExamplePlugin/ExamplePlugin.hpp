/**
 * Ashita Example Plugin - Copyright (c) Ashita Development Team
 * Contact: https://www.ashitaxi.com/
 * Contact: https://discord.gg/Ashita
 *
 * This file is part of Ashita Example Plugin.
 *
 * Ashita Example Plugin is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Ashita Example Plugin is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Ashita Example Plugin.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef ASHITA_EXAMPLEPLUGIN_HPP_INCLUDED
#define ASHITA_EXAMPLEPLUGIN_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/**
 * Main Ashita SDK Include
 * 
 * In order to compile a proper Ashita plugin, this header is required to be included. This header
 * includes the various other generally used parts of the Ashita SDK, as well as defines the various
 * SDK interfaces, enumerations, and other type definitions required.
 * 
 * To help with uniformed pathing, Ashita bases all SDK includes from a parent path. You can set this
 * parent path via the following environment variable on your system: 
 * 
 * ASHITA4_SDK_PATH
 */
#include "Ashita.h"

/**
 * ExamplePlugin Class Implementation
 * 
 * This is the main class object the plugin will create an instance of and return to Ashita when
 * the 'CreatePlugin' export is called. This class MUST inherit from the 'IPlugin' interface to
 * work properly with Ashita.
 */
class ExamplePlugin final : public IPlugin
{
    IAshitaCore* m_AshitaCore;          // The pointer to the main AshitaCore object.
    ILogManager* m_LogManager;          // The pointer to the main Ashita LogManager object.
    uint32_t m_PluginId;                // The plugins id. (The plugins current base address.)
    IDirect3DDevice8* m_Direct3DDevice; // The pointer to the games Direct3D device object.

public:
    ExamplePlugin(void);
    ~ExamplePlugin(void) override;

    // Properties (Plugin Information)
    const char* GetName(void) const override;
    const char* GetAuthor(void) const override;
    const char* GetDescription(void) const override;
    const char* GetLink(void) const override;
    double GetVersion(void) const override;
    double GetInterfaceVersion(void) const override;
    int32_t GetPriority(void) const override;
    uint32_t GetFlags(void) const override;

    // Methods
    bool Initialize(IAshitaCore* core, ILogManager* logger, uint32_t id) override;
    void Release(void) override;

    // Event Callbacks: PluginManager
    void HandleEvent(const char* eventName, const void* eventData, const uint32_t eventSize) override;

    // Event Callbacks: ChatManager
    bool HandleCommand(int32_t mode, const char* command, bool injected) override;
    bool HandleIncomingText(int32_t mode, bool indent, const char* message, int32_t* modifiedMode, bool* modifiedIndent, char* modifiedMessage, bool injected, bool blocked) override;
    bool HandleOutgoingText(int32_t mode, const char* message, int32_t* modifiedMode, char* modifiedMessage, bool injected, bool blocked) override;

    // Event Callbacks: PacketManager
    bool HandleIncomingPacket(uint16_t id, uint32_t size, const uint8_t* data, uint8_t* modified, uint32_t sizeChunk, const uint8_t* dataChunk, bool injected, bool blocked) override;
    bool HandleOutgoingPacket(uint16_t id, uint32_t size, const uint8_t* data, uint8_t* modified, uint32_t sizeChunk, const uint8_t* dataChunk, bool injected, bool blocked) override;

    // Event Callbacks: Direct3D
    bool Direct3DInitialize(IDirect3DDevice8* device) override;
    void Direct3DBeginScene(bool isRenderingBackBuffer) override;
    void Direct3DEndScene(bool isRenderingBackBuffer) override;
    void Direct3DPresent(const RECT* pSourceRect, const RECT* pDestRect, HWND hDestWindowOverride, const RGNDATA* pDirtyRegion) override;
    bool Direct3DSetRenderState(D3DRENDERSTATETYPE State, DWORD* Value) override;
    bool Direct3DDrawPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount) override;
    bool Direct3DDrawIndexedPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT minIndex, UINT NumVertices, UINT startIndex, UINT primCount) override;
    bool Direct3DDrawPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride) override;
    bool Direct3DDrawIndexedPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertexIndices, UINT PrimitiveCount, CONST void* pIndexData, D3DFORMAT IndexDataFormat, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride) override;
};

#endif // ASHITA_EXAMPLEPLUGIN_HPP_INCLUDED