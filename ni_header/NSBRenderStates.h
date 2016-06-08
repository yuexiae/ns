// NUMERICAL DESIGN LIMITED PROPRIETARY INFORMATION
//
// This software is supplied under the terms of a license agreement or
// nondisclosure agreement with Numerical Design Limited and may not 
// be copied or disclosed except in accordance with the terms of that 
// agreement.
//
//      Copyright (c) 1996-2004 Numerical Design Limited.
//      All Rights Reserved.
//
// Numerical Design Limited, Chapel Hill, North Carolina 27514
// http://www.ndl.com

#ifndef NSBRENDERSTATES_H
#define NSBRENDERSTATES_H

#include <NiD3DDefines.h>
#include "NiBinaryShaderLibLibType.h"

// Define modes that may not be available on all platforms!
#ifndef D3DFRONT
    #if defined(_LOG_DEFINED_STATES_)
        #pragma message("Defining D3DFRONT!")
    #endif  //#if defined(_LOG_DEFINED_STATES_)
#define D3DFRONT unsigned int
#endif  //#ifndef D3DFRONT

#ifndef D3DLOGICOP
    #if defined(_LOG_DEFINED_STATES_)
        #pragma message("Defining D3DLOGICOP!")
    #endif  //#if defined(_LOG_DEFINED_STATES_)
#define D3DLOGICOP unsigned int
#endif  //#ifndef D3DLOGICOP

#ifndef D3DMULTISAMPLEMODE
    #if defined(_LOG_DEFINED_STATES_)
        #pragma message("Defining D3DMULTISAMPLEMODE!")
    #endif  //#if defined(_LOG_DEFINED_STATES_)
#define D3DMULTISAMPLEMODE unsigned int
#endif  //#ifndef D3DMULTISAMPLEMODE

#ifndef D3DSWATHWIDTH
    #if defined(_LOG_DEFINED_STATES_)
        #pragma message("Defining D3DSWATHWIDTH!")
    #endif  //#if defined(_LOG_DEFINED_STATES_)
#define D3DSWATHWIDTH unsigned int
#endif  //#ifndef D3DSWATHWIDTH

#ifndef D3DDEBUGMONITORTOKENS
    #if defined(_LOG_DEFINED_STATES_)
        #pragma message("Defining D3DDEBUGMONITORTOKENS")
    #endif  //#if defined(_LOG_DEFINED_STATES_)
#define D3DDEBUGMONITORTOKENS unsigned int
#endif  //#ifndef D3DDEBUGMONITORTOKENS

//
class NIBINARYSHADERLIB_ENTRY NSBRenderStates
{
public:
    enum NiD3DRenderState
    {
        // Simple states
        NID3DRS_ZFUNC       = 0,
        NID3DRS_ALPHAFUNC,
        NID3DRS_ALPHABLENDENABLE,
        NID3DRS_ALPHATESTENABLE,
        NID3DRS_ALPHAREF,
        NID3DRS_SRCBLEND,
        NID3DRS_DESTBLEND,
        NID3DRS_ZWRITEENABLE,
        NID3DRS_DITHERENABLE,
        NID3DRS_SHADEMODE,
        NID3DRS_COLORWRITEENABLE,
        NID3DRS_STENCILZFAIL,
        NID3DRS_STENCILPASS,
        NID3DRS_STENCILFUNC,
        NID3DRS_STENCILREF,
        NID3DRS_STENCILMASK,
        NID3DRS_STENCILWRITEMASK,
        NID3DRS_BLENDOP,
        NID3DRS_BLENDCOLOR,
        NID3DRS_SWATHWIDTH,
        NID3DRS_POLYGONOFFSETZSLOPESCALE,
        NID3DRS_POLYGONOFFSETZOFFSET,
        NID3DRS_POINTOFFSETENABLE,
        NID3DRS_WIREFRAMEOFFSETENABLE,
        NID3DRS_SOLIDOFFSETENABLE,
        NID3DRS_DEPTHCLIPCONTROL,
        NID3DRS_STIPPLEENABLE,
        // Deferred states
        NID3DRS_FOGENABLE,
        NID3DRS_FOGTABLEMODE,
        NID3DRS_FOGSTART,
        NID3DRS_FOGEND,
        NID3DRS_FOGDENSITY,
        NID3DRS_RANGEFOGENABLE,
        NID3DRS_WRAP0,
        NID3DRS_WRAP1,
        NID3DRS_WRAP2,
        NID3DRS_WRAP3,
        NID3DRS_WRAP4,
        NID3DRS_WRAP5,
        NID3DRS_WRAP6,
        NID3DRS_WRAP7,
        NID3DRS_LIGHTING,
        NID3DRS_SPECULARENABLE,
        NID3DRS_LOCALVIEWER,
        NID3DRS_COLORVERTEX,
        NID3DRS_BACKSPECULARMATERIALSOURCE,
        NID3DRS_BACKDIFFUSEMATERIALSOURCE ,
        NID3DRS_BACKAMBIENTMATERIALSOURCE,
        NID3DRS_BACKEMISSIVEMATERIALSOURCE,
        NID3DRS_SPECULARMATERIALSOURCE,
        NID3DRS_DIFFUSEMATERIALSOURCE ,
        NID3DRS_AMBIENTMATERIALSOURCE,
        NID3DRS_EMISSIVEMATERIALSOURCE,
        NID3DRS_BACKAMBIENT,
        NID3DRS_AMBIENT,
        NID3DRS_POINTSIZE,
        NID3DRS_POINTSIZE_MIN,
        NID3DRS_POINTSPRITEENABLE,
        NID3DRS_POINTSCALEENABLE,
        NID3DRS_POINTSCALE_A,
        NID3DRS_POINTSCALE_B,
        NID3DRS_POINTSCALE_C,
        NID3DRS_POINTSIZE_MAX,
        NID3DRS_PATCHEDGESTYLE,
        NID3DRS_PATCHSEGMENTS,
        NID3DRS_SWAPFILTER,
        NID3DRS_PRESENTATIONINTERVAL,
        // Complex state that has immediate processing:
        NID3DRS_VERTEXBLEND,
        NID3DRS_FOGCOLOR,
        NID3DRS_FILLMODE,
        NID3DRS_BACKFILLMODE,
        NID3DRS_TWOSIDEDLIGHTING,
        NID3DRS_NORMALIZENORMALS,
        NID3DRS_ZENABLE,
        NID3DRS_STENCILENABLE,
        NID3DRS_STENCILFAIL,
        NID3DRS_FRONTFACE,
        NID3DRS_CULLMODE,
        NID3DRS_TEXTUREFACTOR,
        NID3DRS_ZBIAS,
        NID3DRS_LOGICOP,
        NID3DRS_EDGEANTIALIAS,
        NID3DRS_MULTISAMPLEANTIALIAS,
        NID3DRS_MULTISAMPLEMASK,
        NID3DRS_MULTISAMPLEMODE,
        NID3DRS_MULTISAMPLERENDERTARGETMODE,
        NID3DRS_SHADOWFUNC,
        NID3DRS_LINEWIDTH,
        NID3DRS_SAMPLEALPHA,
        NID3DRS_DXT1NOISEENABLE,
        NID3DRS_YUVENABLE,
        NID3DRS_OCCLUSIONCULLENABLE,
        NID3DRS_STENCILCULLENABLE,
        NID3DRS_ROPZCMPALWAYSREAD,
        NID3DRS_ROPZREAD,
        NID3DRS_DONOTCULLUNCOMPRESSED,
        // Render states that are not supported on Xbox:
        NID3DRS_LINEPATTERN,
        NID3DRS_LASTPIXEL,
        NID3DRS_CLIPPING,
        NID3DRS_FOGVERTEXMODE,
        NID3DRS_CLIPPLANEENABLE,
        NID3DRS_SOFTWAREVERTEXPROCESSING,
        NID3DRS_DEBUGMONITORTOKEN,
        NID3DRS_INDEXEDVERTEXBLENDENABLE,
        NID3DRS_TWEENFACTOR,
        // PC-DX specifc
        NID3DRS_POSITIONORDER,
        NID3DRS_NORMALORDER,
        // DX9 specific
        NID3DRS_POSITIONDEGREE,
        NID3DRS_NORMALDEGREE,
        NID3DRS_SCISSORTESTENABLE,
        NID3DRS_SLOPESCALEDEPTHBIAS,
        NID3DRS_ANTIALIASEDLINEENABLE,
        NID3DRS_MINTESSELLATIONLEVEL,
        NID3DRS_MAXTESSELLATIONLEVEL,
        NID3DRS_ADAPTIVETESS_X,
        NID3DRS_ADAPTIVETESS_Y,
        NID3DRS_ADAPTIVETESS_Z,
        NID3DRS_ADAPTIVETESS_W,
        NID3DRS_ENABLEADAPTIVETESSELATION,
        NID3DRS_TWOSIDEDSTENCILMODE,
        NID3DRS_CCW_STENCILFAIL,
        NID3DRS_CCW_STENCILZFAIL,
        NID3DRS_CCW_STENCILPASS,
        NID3DRS_CCW_STENCILFUNC,
        NID3DRS_COLORWRITEENABLE1,
        NID3DRS_COLORWRITEENABLE2,
        NID3DRS_COLORWRITEENABLE3,
        NID3DRS_BLENDFACTOR,
        NID3DRS_SRGBWRITEENABLE,
        NID3DRS_DEPTHBIAS,
        NID3DRS_WRAP8,
        NID3DRS_WRAP9,
        NID3DRS_WRAP10,
        NID3DRS_WRAP11,
        NID3DRS_WRAP12,
        NID3DRS_WRAP13,
        NID3DRS_WRAP14,
        NID3DRS_WRAP15,
        NID3DRS_SEPARATEALPHABLENDENABLE,
        NID3DRS_SRCBLENDALPHA,
        NID3DRS_DESTBLENDALPHA,
        NID3DRS_BLENDOPALPHA,
        // Xbox Directly Defined Pixel Shader States
        NID3DRS_PSTEXTUREMODES,
        NID3DRS_PSALPHAINPUTS0,
        NID3DRS_PSALPHAINPUTS1,
        NID3DRS_PSALPHAINPUTS2,
        NID3DRS_PSALPHAINPUTS3,
        NID3DRS_PSALPHAINPUTS4,
        NID3DRS_PSALPHAINPUTS5,
        NID3DRS_PSALPHAINPUTS6,
        NID3DRS_PSALPHAINPUTS7,
        NID3DRS_PSFINALCOMBINERINPUTSABCD,
        NID3DRS_PSFINALCOMBINERINPUTSEFG,
        NID3DRS_PSCONSTANT0_0,
        NID3DRS_PSCONSTANT0_1,
        NID3DRS_PSCONSTANT0_2,
        NID3DRS_PSCONSTANT0_3,
        NID3DRS_PSCONSTANT0_4,
        NID3DRS_PSCONSTANT0_5,
        NID3DRS_PSCONSTANT0_6,
        NID3DRS_PSCONSTANT0_7,
        NID3DRS_PSCONSTANT1_0,
        NID3DRS_PSCONSTANT1_1,
        NID3DRS_PSCONSTANT1_2,
        NID3DRS_PSCONSTANT1_3,
        NID3DRS_PSCONSTANT1_4,
        NID3DRS_PSCONSTANT1_5,
        NID3DRS_PSCONSTANT1_6,
        NID3DRS_PSCONSTANT1_7,
        NID3DRS_PSALPHAOUTPUTS0,
        NID3DRS_PSALPHAOUTPUTS1,
        NID3DRS_PSALPHAOUTPUTS2,
        NID3DRS_PSALPHAOUTPUTS3,
        NID3DRS_PSALPHAOUTPUTS4,
        NID3DRS_PSALPHAOUTPUTS5,
        NID3DRS_PSALPHAOUTPUTS6,
        NID3DRS_PSALPHAOUTPUTS7,
        NID3DRS_PSRGBINPUTS0,
        NID3DRS_PSRGBINPUTS1,
        NID3DRS_PSRGBINPUTS2,
        NID3DRS_PSRGBINPUTS3,
        NID3DRS_PSRGBINPUTS4,
        NID3DRS_PSRGBINPUTS5,
        NID3DRS_PSRGBINPUTS6,
        NID3DRS_PSRGBINPUTS7,
        NID3DRS_PSCOMPAREMODE,
        NID3DRS_PSFINALCOMBINERCONSTANT0,
        NID3DRS_PSFINALCOMBINERCONSTANT1,
        NID3DRS_PSRGBOUTPUTS0,
        NID3DRS_PSRGBOUTPUTS1,
        NID3DRS_PSRGBOUTPUTS2,
        NID3DRS_PSRGBOUTPUTS3,
        NID3DRS_PSRGBOUTPUTS4,
        NID3DRS_PSRGBOUTPUTS5,
        NID3DRS_PSRGBOUTPUTS6,
        NID3DRS_PSRGBOUTPUTS7,
        NID3DRS_PSCOMBINERCOUNT,
        NID3DRS_PSDOTMAPPING,
        NID3DRS_PSINPUTTEXTURE,
        //
        NID3DRS_COUNT,
        NID3DRS_INVALID     = 0x7fffffff
    };

    enum NiD3DZBufferType
    {
        NID3DZB_FALSE   = 0,
        NID3DZB_TRUE,
        NID3DZB_USEW,
        // 
        NID3DZB_COUNT,
        NID3DZB_INVALID = 0x7fffffff
    };

    enum NiD3DFillMode
    {
        NID3DFILL_POINT     = 0,
        NID3DFILL_WIREFRAME,
        NID3DFILL_SOLID,
        // 
        NID3DFILL_COUNT,
        NID3DFILL_INVALID   = 0x7fffffff
    };

    enum NiD3DShadeMode
    {
        NID3DSHADE_FLAT     = 0,
        NID3DSHADE_GOURAUD,
        NID3DSHADE_PHONG,
        // 
        NID3DSHADE_COUNT,
        NID3DSHADE_INVALID  = 0x7fffffff
    };

    enum NiD3DBlend
    {
        NID3DBLEND_ZERO     =  0,
        NID3DBLEND_ONE,
        NID3DBLEND_SRCCOLOR,
        NID3DBLEND_INVSRCCOLOR,
        NID3DBLEND_SRCALPHA,
        NID3DBLEND_INVSRCALPHA,
        NID3DBLEND_DESTALPHA,
        NID3DBLEND_INVDESTALPHA,
        NID3DBLEND_DESTCOLOR,
        NID3DBLEND_INVDESTCOLOR,
        // DX8 only
        NID3DBLEND_SRCALPHASAT,
        NID3DBLEND_BOTHSRCALPHA,
        NID3DBLEND_BOTHINVSRCALPHA,
        // Xbox only
        NID3DBLEND_CONSTANTCOLOR,
        NID3DBLEND_INVCONSTANTCOLOR,
        NID3DBLEND_CONSTANTALPHA,
        NID3DBLEND_INVCONSTANTALPHA,
        // 
        NID3DBLEND_COUNT,
        NID3DBLEND_INVALID  = 0x7fffffff
    };

    enum NiD3DCull
    {
        NID3DCULL_NONE      = 0,
        NID3DCULL_CW,
        NID3DCULL_CCW,
        // 
        NID3DCULL_COUNT,
        NID3DCULL_INVALID   = 0x7fffffff
    };

    enum NiD3DCmpFunc
    {
        NID3DCMP_NEVER    = 0,
        NID3DCMP_LESS,
        NID3DCMP_EQUAL,
        NID3DCMP_LESSEQUAL,
        NID3DCMP_GREATER,
        NID3DCMP_NOTEQUAL,
        NID3DCMP_GREATEREQUAL,
        NID3DCMP_ALWAYS,
        // 
        NID3DCMP_COUNT,
        NID3DCMP_INVALID  = 0x7fffffff
    };

    enum NiD3DFogMode
    {
        NID3DFOG_NONE     = 0,
        NID3DFOG_EXP,
        NID3DFOG_EXP2,
        NID3DFOG_LINEAR,
        // 
        NID3DFOG_COUNT,
        NID3DFOG_INVALID  = 0x7fffffff
    };

    enum NiD3DStencilOp
    {
        NID3DSTENCILOP_KEEP     = 0,
        NID3DSTENCILOP_ZERO,
        NID3DSTENCILOP_REPLACE,
        NID3DSTENCILOP_INCRSAT,
        NID3DSTENCILOP_DECRSAT,
        NID3DSTENCILOP_INVERT,
        NID3DSTENCILOP_INCR,
        NID3DSTENCILOP_DECR,
        // 
        NID3DSTENCILOP_COUNT,
        NID3DSTENCILOP_INVALID  = 0x7fffffff
    };

    enum NiD3DWrap
    {
        NID3DWRAP_DISABLED  = 0,
        NID3DWRAP_U,
        NID3DWRAP_V,
        NID3DWRAP_W,
        NID3DWRAP_UV,
        NID3DWRAP_UW,
        NID3DWRAP_VW,
        NID3DWRAP_UVW,
        // 
        NID3DWRAP_COUNT,
        NID3DWRAP_INVALID   = 0x7fffffff
    };

    enum NiD3DMaterialColorSource
    {
        NID3DMCS_MATERIAL   = 0,
        NID3DMCS_COLOR1,
        NID3DMCS_COLOR2,
        // 
        NID3DMCS_COUNT,
        NID3DMCS_INVALID    = 0x7fffffff
    };

    enum NiD3DVertexBlendFlags
    {
        NID3DVBF_DISABLE    = 0,
        NID3DVBF_1WEIGHTS,
        NID3DVBF_2WEIGHTS,
        NID3DVBF_3WEIGHTS,
        // Xbox only
        NID3DVBF_2WEIGHTS2MATRICES,
        NID3DVBF_3WEIGHTS3MATRICES,
        NID3DVBF_4WEIGHTS4MATRICES,
        // DX only
        NID3DVBF_TWEENING,
        NID3DVBF_0WEIGHTS,
        // 
        NID3DVBF_COUNT,
        NID3DVBF_INVALID    = 0x7fffffff
    };

    enum NiD3DPatchEdgeStyle
    {
        NID3DPATCHEDGE_DISCRETE = 0,
        NID3DPATCHEDGE_CONTINUOUS,
        // 
        NID3DPATCHEDGE_COUNT,
        NID3DPATCHEDGE_INVALID  = 0x7fffffff,
    };

    enum NiD3DDebugMonitorTokens
    {
        NID3DDMT_ENABLE     = 0,
        NID3DDMT_DISABLE,
        // 
        NID3DDMT_COUNT,
        NID3DDMT_INVALID    = 0x7fffffff
    };

    enum NiD3DBlendOp
    {
        NID3DBLENDOP_ADD          = 0,
        NID3DBLENDOP_SUBTRACT,
        NID3DBLENDOP_REVSUBTRACT,
        NID3DBLENDOP_MIN,
        NID3DBLENDOP_MAX,
        // Xbox only
        NID3DBLENDOP_ADDSIGNED,
        NID3DBLENDOP_REVSUBTRACTSIGNED,
        // 
        NID3DBLENDOP_COUNT,
        NID3DBLENDOP_INVALID    = 0x7fffffff
    };

    enum NiD3DSwathWidth
    {
        NID3DSWATH_8        = 0,
        NID3DSWATH_16,
        NID3DSWATH_32,
        NID3DSWATH_64,
        NID3DSWATH_128,
        NID3DSWATH_OFF,
        // 
        NID3DSWATH_COUNT,
        NID3DSWATH_INVALID  = 0x7fffffff
    };

    enum NiD3DOrderType
    {
        NID3DORDER_LINEAR   = 0,
        NID3DORDER_QUADRATIC, 
        NID3DORDER_CUBIC,
        NID3DORDER_QUINTIC, 
        // 
        NID3DORDER_COUNT,
        NID3DORDER_INVALID  = 0x7fffffff
    };

    // Xbox only
    enum NiD3DDepthClipControl
    {
        NID3DDCC_CULLPRIMITIVE  = 0,
        NID3DDCC_CLAMP,
        NID3DDCC_IGNORE_W_SIGN,
        // 
        NID3DDCC_COUNT,
        NID3DDCC_INVALID        = 0x7fffffff
    };

    enum NiD3DTextureFilterType
    {
        NID3DTEXF_NONE          = 0,
        NID3DTEXF_POINT,
        NID3DTEXF_LINEAR,
        NID3DTEXF_ANISOTROPIC,
        NID3DTEXF_QUINCUNX,
        NID3DTEXF_GAUSSIANCUBIC,
        NID3DTEXF_MAX,
        // 
        NID3DTEXF_COUNT,
        NID3DTEXF_FORCE_DWORD   = 0x7fffffff
    };

    // Xbox only
    enum NiD3DPresentIntervalType
    {
        NID3DPRESENT_INTERVAL_IMMEDIATE = 0,
        NID3DPRESENT_INTERVAL_ONE,
        NID3DPRESENT_INTERVAL_ONE_OR_IMMEDIATE,
        NID3DPRESENT_INTERVAL_TWO,
        NID3DPRESENT_INTERVAL_TWO_OR_IMMEDIATE,
        NID3DPRESENT_INTERVAL_THREE,
        NID3DPRESENT_INTERVAL_THREE_OR_IMMEDIATE,
        NID3DPRESENT_INTERVAL_FOUR,
        // 
        NID3DPRESENT_INTERVAL_COUNT,
        NID3DPRESENT_INTERVAL_INVALID   = 0x7fffffff
    };

    // Xbox only
    enum NiD3DFront
    {
        NID3DFRONT_CW       = 0,
        NID3DFRONT_CCW,
        // 
        NID3DFRONT_COUNT,
        NID3DFRONT_INVALID  = 0x7fffffff
    };

    // Xbox only
    enum NiD3DLogicOp
    {
        NID3DLOGICOP_NONE       = 0,
        NID3DLOGICOP_CLEAR,
        NID3DLOGICOP_AND,
        NID3DLOGICOP_AND_REVERSE,
        NID3DLOGICOP_COPY,
        NID3DLOGICOP_AND_INVERTED,
        NID3DLOGICOP_NOOP,
        NID3DLOGICOP_XOR,
        NID3DLOGICOP_OR,
        NID3DLOGICOP_NOR,
        NID3DLOGICOP_EQUIV,
        NID3DLOGICOP_INVERT,
        NID3DLOGICOP_OR_REVERSE,
        NID3DLOGICOP_COPY_INVERTED,
        NID3DLOGICOP_OR_INVERTED,
        NID3DLOGICOP_NAND,
        NID3DLOGICOP_SET,
        // 
        NID3DLOGICOP_COUNT,
        NID3DLOGICOP_INVALID    = 0x7fffffff
    };

    // 
    enum NiD3DMultiSampleModeType
    {
        NID3DMULTISAMPLEMODE_1X         = 0,
        NID3DMULTISAMPLEMODE_2X,
        NID3DMULTISAMPLEMODE_4X,
        // 
        NID3DMULTISAMPLEMODE_COUNT,
        NID3DMULTISAMPLEMODE_INVALID    = 0x7fffffff
    };

    // 
    enum NiD3DSampleAlphaType
    {
        NID3DSAMPLEALPHA_TOCOVERAGE = 0,
        NID3DSAMPLEALPHA_TOONE,
        // 
        NID3DSAMPLEALPHA_COUNT,
        NID3DSAMPLEALPHA_INVALID    = 0x7fffffff
    };

    // DX9
    enum NiD3DDegreeType
    {
        NID3DDEGREE_LINEAR      = 1,
        NID3DDEGREE_QUADRATIC   = 2,
        NID3DDEGREE_CUBIC       = 3,
        NID3DDEGREE_QUINTIC     = 5,
        NID3DDEGREE_INVALID     = 0x7fffffff
    };

    static bool ConvertNSBRenderStateValue(
        NiD3DRenderState eNSBState, unsigned int uiNSBValue,
        unsigned int& uiD3DValue);

    static NiD3DRenderState LookupRenderState(const char* pszRenderState);
    static bool LookupRenderStateValue(NiD3DRenderState eRenderState, 
        const char* pszValue, unsigned int& uiValue);

    static bool GetD3DRenderStateType(NiD3DRenderState eRenderState,
        D3DRENDERSTATETYPE& eD3DRS);
    static bool GetD3DZBufferType(NiD3DZBufferType eZBufferType, 
        unsigned int& uiD3DValue);
    static bool GetD3DFillMode(NiD3DFillMode eFillMode, 
        unsigned int& uiD3DValue);
    static bool GetD3DShadeMode(NiD3DShadeMode eShadeMode, 
        unsigned int& uiD3DValue);
    static bool GetD3DBlend(NiD3DBlend eBlend, unsigned int& uiD3DValue);
    static bool GetD3DCull(NiD3DCull eCull, unsigned int& uiD3DValue);
    static bool GetD3DCmpFunc(NiD3DCmpFunc eCmpFunc, 
        unsigned int& uiD3DValue);
    static bool GetD3DFogMode(NiD3DFogMode eFogMode, 
        unsigned int& uiD3DValue);
    static bool GetD3DStencilOp(NiD3DStencilOp eStencilOp, 
        unsigned int& uiD3DValue);
    static bool GetD3DWrap(NiD3DWrap eWrap, unsigned int& uiD3DValue);
    static bool GetD3DMaterialColorSource(
        NiD3DMaterialColorSource eMaterialColorSource, 
        unsigned int& uiD3DValue);
    static bool GetD3DVertexBlendFlags(
        NiD3DVertexBlendFlags eVertexBlendFlags, 
        unsigned int& uiD3DValue);
    static bool GetD3DPatchEdgeStyle(NiD3DPatchEdgeStyle ePatchEdgeStyle, 
        unsigned int& uiD3DValue);
    static bool GetD3DDebugMonitorTokens(
        NiD3DDebugMonitorTokens eDebugMonitorTokens, 
        unsigned int& uiD3DValue);
    static bool GetD3DBlendOp(NiD3DBlendOp eBlendOp, 
        unsigned int& uiD3DValue);
    static bool GetD3DSwathWidth(NiD3DSwathWidth eSwathWidth, 
        unsigned int& uiD3DValue);
    static bool GetD3DOrderType(NiD3DOrderType eOrderType, 
        unsigned int& uiD3DValue);
    static bool GetD3DDepthClipControl(
        NiD3DDepthClipControl eDepthClipControl, 
        unsigned int& uiD3DValue);
    static bool GetD3DTextureFilterType(
        NiD3DTextureFilterType eTextureFilterType, 
        unsigned int& uiD3DValue);
    static bool GetD3DPresentationIntervalType(
        NiD3DPresentIntervalType ePresentIntervalType, 
        unsigned int& uiD3DValue);
    static bool GetD3DFront(NiD3DFront eFront, unsigned int& uiD3DValue);
    static bool GetD3DLogicOp(NiD3DLogicOp eLogicOp, 
        unsigned int& uiD3DValue);
    static bool GetD3DMultiSampleMode(
        NiD3DMultiSampleModeType eMultiSampleModeType, 
        unsigned int& uiD3DValue);
    static bool GetD3DSampleAlphaType(NiD3DSampleAlphaType eSampleAlphaType, 
        unsigned int& uiD3DValue);
    static bool GetD3DDegreeType(NiD3DDegreeType eDegreeType, 
        unsigned int& uiD3DValue);

#if defined(_DEBUG)
    static const char* LookupRenderStateString(NiD3DRenderState eRS);
#endif  //#if defined(_DEBUG)

protected:
    static D3DRENDERSTATETYPE ms_aeRenderStateLUT[NID3DRS_COUNT];
    static D3DZBUFFERTYPE ms_aeZBufferTypeLUT[NID3DZB_COUNT];
    static D3DFILLMODE ms_aeFillModeLUT[NID3DFILL_COUNT];
#if !defined(_XENON)
    static D3DSHADEMODE ms_aeShadeModeLUT[NID3DSHADE_COUNT];
#endif  //#if !defined(_XENON)
    static D3DBLEND ms_aeBlendLUT[NID3DBLEND_COUNT];
    static D3DCULL ms_aeCullLUT[NID3DCULL_COUNT];
    static D3DCMPFUNC ms_aeCmpFuncLUT[NID3DCMP_COUNT];
    static D3DFOGMODE ms_aeFogModeLUT[NID3DFOG_COUNT];
    static D3DSTENCILOP ms_aeStencilOpLUT[NID3DSTENCILOP_COUNT];
    static unsigned int ms_auiWrapLUT[NID3DWRAP_COUNT];
    static D3DMATERIALCOLORSOURCE ms_aeMaterialColorSourceLUT[NID3DMCS_COUNT];
    static D3DVERTEXBLENDFLAGS ms_aeVertexBlendFlagsLUT[NID3DVBF_COUNT];
    static D3DPATCHEDGESTYLE ms_aePatchEdgeStyleLUT[NID3DPATCHEDGE_COUNT];
    static D3DDEBUGMONITORTOKENS ms_aeDebugMonitorTokensLUT[NID3DDMT_COUNT];
    static D3DBLENDOP ms_aeBlendOpLUT[NID3DBLENDOP_COUNT];
    static D3DSWATHWIDTH ms_aeSwathWidth[NID3DSWATH_COUNT];
#if defined(_DX8) || (defined(_XBOX) && !defined(_XENON))
    static D3DORDERTYPE ms_aeOrderTypeLUT[NID3DORDER_COUNT];
#endif  //#if defined(_DX8) || (defined(_XBOX) && !defined(_XENON))
    static unsigned int ms_auiDepthClipControlLUT[NID3DDCC_COUNT];
    static D3DTEXTUREFILTERTYPE ms_aeTextureFilterTypeLUT[NID3DTEXF_COUNT];
    static unsigned int ms_auiPresentationIntervalTypeLUT[NID3DPRESENT_INTERVAL_COUNT];
    static D3DFRONT ms_aeFrontLUT[NID3DFRONT_COUNT];
    static D3DLOGICOP ms_aeLogicOpLUT[NID3DLOGICOP_COUNT];
    static D3DMULTISAMPLEMODE ms_aeMultiSampleModeLUT[NID3DMULTISAMPLEMODE_COUNT];
    static unsigned int ms_auiSampleAlphaTypeLUT[NID3DSAMPLEALPHA_COUNT];

};

#endif  //NSBRENDERSTATES_H
