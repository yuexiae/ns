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

#ifndef NISCENEGRAPHSHAREDDATA_H
#define NISCENEGRAPHSHAREDDATA_H

#include "NiStandardSharedDataLibType.h"
#include "NiSharedData.h"
#include "NiPluginToolkitDefinitions.h"
#include "NiTPtrSet.h"
#include <NiNode.h>
#include "NiString.h"



/// This class indicates which scene graph is currently in use. The scene
/// graph shared data object is one of the basic shared data objects
/// provided by NDL.
class NISTANDARDSHAREDDATA_ENTRY NiSceneGraphSharedData : public NiSharedData
{
public:
    NiDeclareRTTI;

    /// Default constructor.
    NiSceneGraphSharedData();

    /// Virtual destructor.
    virtual ~NiSceneGraphSharedData();

    /// Adds a root into the root array. This broadcasts a message to any
    /// handlers.
    void AddRoot(NiNode* pkRoot, const char* pcName = "",
        bool bStreamable = true,
        NiPluginToolkitRenderer ePlatform = RENDER_DX8);

    /// Removes root from the root list. This broadcasts a message to any
    /// handlers.
    NiNodePtr RemoveRoot(NiNode* pkRoot);

    /// Removes all the roots from the root list. This broadcasts a message
    /// for each root removed.
    void RemoveAllRoots();

    /// Update all of the roots. This broadcasts a message to any handlers.
    void UpdateAll(float fTime);

    /// Update a specific root. This broadcasts a message to any handlers.
    void UpdateRoot(NiNode* pkRoot, float fTime);

    /// Get the total number of roots in the system
    unsigned int GetRootCount();

    /// Get a root out of the shared data by index.
    NiNode* GetRootAt(unsigned int uiIndex);

    /// Returns the stored name of the specified root node.
    NiString GetRootName(NiNode* pkRoot);

    /// Returns whether or not the specified root node is streamable.
    bool IsRootStreamable(NiNode* pkRoot);

    /// Returns what the default platform for the root is
    NiPluginToolkitRenderer GetRootPlatform(NiNode* pkRoot);

    /// Returns the last time that the specified root node was updated at.
    float GetLastUpdateTime(NiNode* pkRoot);

    /// Returns all root nodes attached as children of an empty node.
    NiNodePtr GetFullSceneGraph();


protected:

    /// Updates the shared data elements associated with the scene graph.
    void UpdateAssociatedSharedData();

    /// The main root node for all added root nodes.
    NiNodePtr m_spMainRoot;

    /// The set of scene root nodes. This set is provided for convenience
    /// only. The root nodes are "owned" by m_spMainRoot.
    NiTPtrSet<NiNode*> m_kSceneRoots;

    class NodeInfo : public NiRefObject
    {
    public:
        NodeInfo(NiString strName, bool bStreamable, 
            NiPluginToolkitRenderer ePlatform)
        {
            m_strName = strName;
            m_bStreamable = bStreamable;
            m_fLastUpdateTime = 0.0f;
            m_ePlatform = ePlatform;
        }

        NiString m_strName;
        bool m_bStreamable;
        float m_fLastUpdateTime;
        NiPluginToolkitRenderer m_ePlatform;
    };
    typedef NiPointer<NodeInfo> NodeInfoPtr;

    /// The names and streamability corresponding to the root nodes.
    NiTMap<NiNode*, NodeInfoPtr> m_kNodeInfoMap;

};

NiSmartPointer(NiSceneGraphSharedData);

#endif  // #ifndef NISCENEGRAPHSHAREDDATA_H
