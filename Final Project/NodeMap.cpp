#include "NodeMap.h"




NodeMap::NodeMapNode::NodeMapNode(Node *initNode, NodeMapNode* initLeft /*= 0*/, NodeMapNode* initRight /*= 0*/)
{
	node  = initNode;
	left  = initLeft;
	right = initRight;
}

void NodeMap::informIdRemoved(const string &oldValue)
{

}

NodeMap::~NodeMap()
{

}
