//
// Created by Platholl on 15/05/2020.
//

#include "Model/TextDetection/TextDetection.hpp"

TextDetection::TextDetection()
{
    try
    {
        py::exec(R"(
            import sys
            sys.path.insert(0,'py')
        )");

        textDetection = py::module::import("text_detection");
        textCorrection = py::module::import("text_correction");

        textAnalyser = py::module::import("nlp");
        textDetection.attr("load_model")();
        textAnalyser.attr("init_nlp_module")();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

std::string TextDetection::Process(const cv::Mat& src)
{
    try
    {
        py::object result = textDetection.attr("read_text_from_image")(src);
        auto output = result.cast<std::string>();
        return output;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return "";
    }
}


std::string TextDetection::Correct(const std::string& paragraph)
{
    try
    {
        return textCorrection.attr("correct_sentence")(paragraph).cast<std::string>();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return "";
    }
}

std::map<std::string, std::string> TextDetection::AnalyseText(const std::string& text)
{
    try
    {
        py::object result = textAnalyser.attr("process_text")(text);
        return result.cast<std::map<std::string, std::string>>();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return {};
    }
}