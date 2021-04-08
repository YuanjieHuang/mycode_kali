import java.util.ArrayList;   
   
import javax.swing.tree.DefaultMutableTreeNode;   
import javax.swing.tree.DefaultTreeModel;   
   
   
public class CaculateMinCutset {   
       
    private DefaultTreeModel faultTree;   
    private DefaultMutableTreeNode root;   
    private ArrayList<Node> nodes;   
       
    public CaculateMinCutset(ArrayList<Node> nodeList, DefaultTreeModel model){   
        nodes = nodeList;   
        faultTree = model;   
        root = (DefaultMutableTreeNode)faultTree.getRoot();        
    }      
       
    public DefaultMutableTreeNode getDestNode(String name){   
        DefaultMutableTreeNode nextLeaf = root.getFirstLeaf();   
        while(nextLeaf != null){   
            if(name.equals((String)nextLeaf.getUserObject()))   
                return nextLeaf;   
            else   
                nextLeaf = nextLeaf.getNextLeaf();   
        }   
        return null;   
    }   
       
    @SuppressWarnings("unchecked")   
    public ArrayList<ArrayList<DefaultMutableTreeNode>> deepMultiply(ArrayList<ArrayList<DefaultMutableTreeNode>> array1,   
            ArrayList<ArrayList<DefaultMutableTreeNode>> array2){   
        ArrayList<ArrayList<DefaultMutableTreeNode>> newArray = new ArrayList<ArrayList<DefaultMutableTreeNode>>();   
        for(int i = 0; i < array2.size(); i++){   
            ArrayList<DefaultMutableTreeNode> nodes2 = (ArrayList<DefaultMutableTreeNode>)array2.get(i).clone();   
            for(int j = 0; j < array1.size(); j++){   
                ArrayList<DefaultMutableTreeNode> nodes1 = (ArrayList<DefaultMutableTreeNode>)array1.get(j).clone();   
                nodes1.addAll(nodes1.size(),nodes2);   
                newArray.add(nodes1);   
            }   
               
        }   
        return newArray;   
    }   
       
    public ArrayList<DefaultMutableTreeNode> multiply(ArrayList<DefaultMutableTreeNode> nodes1,ArrayList<DefaultMutableTreeNode> nodes2){   
        ArrayList<DefaultMutableTreeNode> newNode = nodes1;   
        newNode.addAll(nodes1.size(),nodes2);   
        return newNode;   
    }   
       
    public ArrayList<ArrayList<DefaultMutableTreeNode>> plus(ArrayList<ArrayList<DefaultMutableTreeNode>> array1,   
            ArrayList<ArrayList<DefaultMutableTreeNode>> array2){   
        ArrayList<ArrayList<DefaultMutableTreeNode>> newArray = array1;   
        newArray.addAll(array1.size(),array2);   
        return newArray;   
    }   
       
    public ArrayList<ArrayList<DefaultMutableTreeNode>> caculate(DefaultMutableTreeNode node){   
        int childcount = node.getChildCount();   
        String gate = getGate(node);   
        ArrayList<ArrayList<DefaultMutableTreeNode>> newArray = new ArrayList<ArrayList<DefaultMutableTreeNode>>();   
        if(childcount > 0){   
            newArray = caculate((DefaultMutableTreeNode)node.getChildAt(0));   
            for(int i = 1; i < childcount; i++){   
                ArrayList<ArrayList<DefaultMutableTreeNode>> array = caculate((DefaultMutableTreeNode)node.getChildAt(i));   
                if(gate.equals("+"))   
                    newArray = plus(newArray, array);   
                else   
                    newArray = deepMultiply(newArray, array);   
            }   
        }   
        else{   
            ArrayList<DefaultMutableTreeNode> array = new ArrayList<DefaultMutableTreeNode>();   
            array.add(node);   
            newArray.add(array);   
        }   
        return newArray;   
    }   
       
    public String getGate(DefaultMutableTreeNode node){   
        String name = (String)node.getUserObject();   
        for(int i = 0; i < nodes.size(); i++){   
            Node newNode = nodes.get(i);   
            if(name.equals(newNode.name)){   
                return newNode.gate;   
            }   
        }   
        return "*";   
    }   
       
    public ArrayList<ArrayList<DefaultMutableTreeNode>> getResult(){       
        ArrayList<ArrayList<DefaultMutableTreeNode>> array;   
        array = caculate(root);        
        return array;   
    }   
}   