#include "pugixml.hpp"
#include <iostream>
#include <stdio.h>
#include <string.h>

void load_string(pugi::xml_document *doc);
void load_string1(pugi::xml_document *doc);

void insert_node(pugi::xml_document *doc)
{
    pugi::xml_node node = doc->child ("isomsg");

    for ( pugi::xml_node fieldFound: doc->child("isomsg"))
    {
        int id = fieldFound.attribute("id").as_int();
        std::string value = fieldFound.attribute("value").as_string();
        
        if (id == 49){
            std::cout << "Found field " <<  " id=" << id << "\n";
            pugi::xml_node de50 = node.insert_child_after("field", fieldFound);
            de50.append_attribute("id") = "51";
            de50.append_attribute("value") = "10";
            return;
        }
    }


}
void insert_node(pugi::xml_document *doc, int previus_node, int inodeIn, const char * valor)
{
    pugi::xml_node node = doc->child ("isomsg");

    for ( pugi::xml_node fieldFound: doc->child("isomsg") )
    {
        int id = fieldFound.attribute("id").as_int();
        //std::string value = fieldFound.attribute("value").as_string();
        
        if ( id == previus_node ){
            //std::cout << "Found field " <<  " id=" << id << "\n";
            pugi::xml_node newDe = node.insert_child_after("field", fieldFound);
            newDe.append_attribute("id") = inodeIn;
            newDe.append_attribute("value") = valor;
            return;
        }
    }
}

void remove_node(pugi::xml_document *doc, int nodeIn, char * attr)
{
    pugi::xml_node nodeRoot = doc->child ("isomsg");

    for ( pugi::xml_node nodeFound: nodeRoot) 
    {
        int id = nodeFound.attribute(attr).as_int();
        
        if ( id== nodeIn ){
            nodeRoot.remove_child(nodeFound);
            return;
        }
    }
}

void remove_node_string(pugi::xml_document *doc, std::string nodeIn, char * attr)
{
    pugi::xml_node nodeRoot = doc->child ("isomsg");

    for ( pugi::xml_node nodeFound: nodeRoot) 
    {
        std::string id = nodeFound.attribute(attr).as_string();
        
        if ( id == nodeIn ){
            nodeRoot.remove_child(nodeFound);
            return;
        }
    }
}

int main()
{
    pugi::xml_document doc;
    //pugi::xml_parse_result result = doc.load_file("isomsg.xml");
    //if (!result)
      //  return -1;

    

    load_string(&doc);
    insert_node(&doc);
    std::string merda="muita merda";
    insert_node(&doc, 23, 24, merda.c_str());
    remove_node(&doc, 22, (char *)"id");
    remove_node(&doc, 51, (char *)"id");
    remove_node_string(&doc, "840", (char *)"value");
  
    doc.print(std::cout);

    

    return (0);
}

void searchNode(pugi::xml_document *doc)
{
    //load_string1(&doc);
    //FUNCIONA MAIS ACHEI MAIS COMPLEXA...
    /*    
    for ( pugi::xml_node field: doc->child("isomsg").children("field") )
    {
        int id = field.attribute("id").as_int();
        std::string value = field.attribute("value").as_string();
        
        if (id == 43){
            std::cout << "field " <<  " id=" << id ;
        }
        //if ( ! value.empty() ){
        //     std::cout  << " value=" << value << "\n";
       // }
    }
    */
}
/*
    for (pugi::xml_node tool: doc.child("Profile").child("Tools").children("Tool"))
    {
        int timeout = tool.attribute("Timeout").as_int();
        std::string AllowRemote = tool.attribute("AllowRemote").as_string();
        
        if (timeout > 0){
            std::cout << "Tool " << tool.attribute("Filename").value() << " has timeout " << timeout << "\n";
        }
        if ( ! AllowRemote.empty() ){
             std::cout << "Tool " << tool.attribute("Filename").value() << " has AllowRemote " << AllowRemote << "\n";
        }
    }


*/
/*
<!-- org.jpos.iso.packager.GenericPackager[MCPackager.xml] -->
*/
void load_string(pugi::xml_document *doc){
    pugi::xml_parse_result result = doc->load_string(R"(<isomsg direction = "incoming">
    <!-- org.jpos.iso.packager.GenericPackager[MCPackager.xml] -->

<field id="0"  value="0100"/>
<field id="2"  value="5558487820679243"/>
<field id="3"  value="000000"/>
<field id="4"  value="000000001500"/>
<field id="6"  value="000000002931"/>
<field id="7"  value="0423171420"/>
<field id="10" value="61954000"/>
<field id="11" value="000002"/>
<field id="12" value="171420"/>
<field id="13" value="0423"/>
<field id="14" value="2803"/>
<field id="15" value="0423"/>
<field id="16" value="0423"/>
<field id="18" value="5999"/>
<field id="22" value="072"/>
<field id="23" value="000"/>
<field id="32" value="999901"/>
<field id="35" value="5558487820679243D28032060000036700"/>
<field id="37" value="085110100001"/>
<field id="41" value="MTF TEST"/>
<field id="42" value="ABC123TESTMTF19"/>
<field id="43" value="Misc Retail            Vegas         NV "/>
<field id="48" value="R"/>
<field id="49" value="840"/>
<field id="51" value="986"/>
<field id="52" value="F4CAB193CF2D223B" type="binary"/>
<field id="55" value="5F2A020840820258008407A0000000041010950500000000009A032004239C01009F0206000000001500 9F10 12 0114250000044000DAC100000000000000009F1A0208409F260893F345646F9C96219F2701809F3303E0E8E89F34034103029F360200019F3704354551AE" type="binary"/>
<field id="61" value="000000000030003263129-1234"/>
<field id="63" value="MRG011SKN"/>

</isomsg>
)");
}
void load_string0(pugi::xml_document *doc){
    pugi::xml_parse_result result = doc->load_string(R"(<isomsg direction = "incoming">
<!-- org.jpos.iso.packager.GenericPackager[MCPackager.xml] -->

<field id="0"  value="0100"/>
<field id="2"  value="5558487820679243"/>
<field id="3"  value="000000"/>
<field id="4"  value="000000001500"/>
<field id="6"  value="000000002931"/>
<field id="7"  value="0423171420"/>
<field id="10" value="61954000"/>
<field id="11" value="000002"/>
<field id="12" value="171420"/>
<field id="13" value="0423"/>
<field id="14" value="2803"/>
<field id="15" value="0423"/>
<field id="16" value="0423"/>
<field id="18" value="5999"/>
<field id="22" value="072"/>
<field id="23" value="000"/>
<field id="32" value="999901"/>
<field id="35" value="5558487820679243D28032060000036700"/>
<field id="37" value="085110100001"/>
<field id="41" value="MTF TEST"/>
<field id="42" value="ABC123TESTMTF19"/>
<field id="43" value="Misc Retail            Vegas         NV "/>
<field id="48" value="R"/>
<field id="49" value="840"/>
<field id="51" value="986"/>
<field id="52" value="F4CAB193CF2D223B" type="binary"/>
<field id="55" value="5F2A020840820258008407A0000000041010950500000000009A032004239C01009F0206000000001500 9F10 12 0114250000044000DAC100000000000000009F1A0208409F260893F345646F9C96219F2701809F3303E0E8E89F34034103029F360200019F3704354551AE" type="binary"/>
<field id="61" value="000000000030003263129-1234"/>
<field id="63" value="MRG011SKN"/>

</isomsg>
)");

/*
   const char source[] = "<mesh name='sphere'><bounds>0 0 1 1</bounds></mesh>";
size_t size = sizeof(source);

// You can use load_buffer_inplace to load document from mutable memory block; the block's lifetime must exceed that of document
char* buffer = new char[size];
memcpy(buffer, source, size);

// The block can be allocated by any method; the block is modified during parsing
//pugi::xml_parse_result result = 
doc->load_buffer_inplace(buffer, size);
 */

//pugi::xml_node node0 = doc->child("isomsg");
//node0.attribute("id=63") = 123;

// add node with some name
pugi::xml_node node = doc->child ("isomsg").child("field");

//descr.append_child(pugi::node_pcdata).set_value("Simple node");
//pugi::xml_node field = node.child("node");
// add param node before the description

// add field node with text child
//node.append_child("field");
//pugi::xml_node de120 = node.insert_child_before("field", field3.a);
pugi::xml_node de120 = node.append_child("field");// .last_child();
// add attributes to de120 node
de120.append_attribute("id") = "120";
de120.append_attribute("value") = 1.1;
de120.insert_attribute_after("type", de120.attribute("name")) = "string";

doc->print(std::cout);
/*
    pugi::xml_node tools= doc->child("isomsg");
    for (pugi::xml_node_iterator it = tools.begin(); it != tools.end(); ++it)
    {
        std::cout << "Tool:";

        for (pugi::xml_attribute_iterator ait = it->attributes_begin(); ait != it->attributes_end(); ++ait)
        {
            std::cout << " " << ait->name() << "=" << ait->value();
        }

        std::cout << std::endl;
    } 
*/
}

void load_string1(pugi::xml_document *doc){
    pugi::xml_parse_result result = doc->load_string(R"( <?xml version="1.0" encoding="UTF-8" standalone="no" ?>
<Profile FormatVersion="1">
<Tools>
        <Tool Filename="jam" AllowIntercept="true">
        	<Description>Jamplus build system</Description>
        </Tool>
        <Tool Filename="mayabatch.exe" AllowRemote="true" OutputFileMasks="*.dae" DeriveCaptionFrom="lastparam" Timeout="40" />
        <Tool Filename="meshbuilder_*.exe" AllowRemote="false" OutputFileMasks="*.mesh" DeriveCaptionFrom="lastparam" Timeout="10" />
        <Tool Filename="texbuilder_*.exe" AllowRemote="true" OutputFileMasks="*.tex" DeriveCaptionFrom="lastparam" />
        <Tool Filename="shaderbuilder_*.exe" AllowRemote="true" DeriveCaptionFrom="lastparam" />
        <Tools/>
</Profile>  )");
    
        
    for (pugi::xml_node tool: doc->child("Profile").child("Tools").children("Tool") )
    {
        int timeout = tool.attribute("Timeout").as_int();
        
        //if (timeout > 0)
            std::cout << "Tool " << tool.attribute("Filename").value() << " has timeout " << timeout << "\n";
    }
}

int mainfunciona()
{
    pugi::xml_document doc;

    auto declarationNode = doc.append_child(pugi::node_declaration);
    declarationNode.append_attribute("version")    = "1.0";
    declarationNode.append_attribute("encoding")   = "ISO-8859-1";
    declarationNode.append_attribute("standalone") = "yes";

    // add node with some name
    pugi::xml_node node = doc.append_child("isomsg");

    // add description node
    pugi::xml_node descr = node.append_child("description");
    //descr.append_child(pugi::node_pcdata).set_value("Simple node");
    descr.append_attribute("id") = "50";
    descr.append_attribute("value") = 10;

    // add hello node
    pugi::xml_node demo = node.append_child("hello");
    demo.append_child(pugi::node_pcdata).set_value("world");

	
    //insert child param after description
    pugi::xml_node param = node.insert_child_after("param", descr);

    // add attributes to param node
    param.append_attribute("name") = "version";
    param.append_attribute("value") = 1.1;
    param.append_attribute("type") = "float";
  
    insert_node(&doc);
    doc.print(std::cout);
    return (0);
}

