#include "textModel.hpp"
#include <string>

TextModel::TextModel(std::string text):
text(text){

}

std::string TextModel::getText() const{
    return text;
}

void TextModel::setText(std::string text){
    this->text = text;
}