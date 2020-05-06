//
// Created by Platholl on 06/05/2020.
//

#include "DatasetBuilder/DatasetImage.hpp"

namespace DatasetBuilder {
    DatasetImage::DatasetImage(const std::string& path) :
        m_src(cv::imread(path)),
        m_srcPath(path)
    {}
    void DatasetImage::Save(const std::string& outputFolder) const
    {
        std::string fileName = outputFolder + m_srcPath.stem().string();
        cv::imwrite(fileName + ".jpg", m_src);

        std::ofstream outfile ("test.txt");
        outfile << m_text << std::endl;
        outfile.close();
    }

    void DatasetImage::Text(const std::string& nText) { m_text = nText; }

    const cv::Mat& DatasetImage::Image() const { return m_src; }

}