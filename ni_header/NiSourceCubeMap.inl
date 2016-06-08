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

//---------------------------------------------------------------------------
inline NiSourceCubeMap::FaceID 
    NiSourceCubeMap::GetCurrentCubeFace() const
{
    return m_eFace;
}
//---------------------------------------------------------------------------
inline void NiSourceCubeMap::SetCurrentCubeFace(FaceID eFace)
{
    if (m_eFace != eFace)
    {
        m_eFace = eFace;

        // swap in the other matching array values to the base class members
        m_spSrcPixelData = m_aspFaceSrcPixelDatas[m_eFace];

        delete[] m_pcFilename;
        delete[] m_pcPlatformFilename;
        if (m_apcFaceFilenames[m_eFace])
        {
            m_pcFilename = new char[strlen(m_apcFaceFilenames[m_eFace]) + 1];
            strcpy(m_pcFilename, m_apcFaceFilenames[m_eFace]);

            assert (m_apcFacePlatformFilenames[m_eFace]);
            m_pcPlatformFilename = 
                new char[strlen(m_apcFaceFilenames[m_eFace]) + 1];
            strcpy(m_pcPlatformFilename, m_apcFacePlatformFilenames[m_eFace]);
        }
        else
        {
            m_pcFilename = NULL;
            m_pcPlatformFilename = NULL;
        }
    }
}
//---------------------------------------------------------------------------
inline const char* NiSourceCubeMap::GetFaceFilename(FaceID eFace) const
{
    return m_apcFaceFilenames[eFace];
}
//---------------------------------------------------------------------------
inline const char* NiSourceCubeMap::GetFacePlatformFilename(FaceID eFace)
    const
{
    return m_apcFacePlatformFilenames[eFace];
}
//---------------------------------------------------------------------------
inline NiPixelData* NiSourceCubeMap::GetFaceSourcePixelData(FaceID eFace) 
    const
{
    return m_aspFaceSrcPixelDatas[eFace];
}
//---------------------------------------------------------------------------
