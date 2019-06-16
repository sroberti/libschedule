#include <unordered_map>
#include <unordered_set>
#include <memory>


namespace dg
{
  /*
    Glossary of terms used:

    Directed Graph: A templated class that defines a set of nodes and directed edges.
    It may contain no loops while edge direction is respected.  Graph connectivity
    cannot be mutated during sorting.  If constructed in an
    invalid state, will throw an appropriate exception.

    Node: A templated class that represents the objects being sorted by the graph.
    Each may have any number of predecessors and may have any number of successors.

    Edge:  A set of exactly two nodes, with one explicitly and constantly defined as
    the predecessor, and the other defined as the successor.

    Head:  A maximal element of the poset.  In other words, a Node that is not
    preceded by any other Node.

    Tail:  A minimal element of the poset.  In other words, a Node that is not
    succeeded by any other Node.

    Floating:  A floating Node is both a Head and a Tail.
   */


  template <typename T>
  class directed_graph
  {
  public:
    directed_graph();
    ~directed_graph();

    //Run a function on every node, in no guaranteed order.
    template <typename F>
    void map(F&) const;

    // Return a subgraph based on some criteria.
    directed_graph<T> getAllPredecessors(const T&) const;
    directed_graph<T> getAllSuccessors(const T&) const;
    template <typename F>
    directed_graph<T> getCulledSubgraph(F&) const;



  private:
    class node
    {
    public:
      node();
      node(const T&);
      ~node();

      T& get() const;
      bool isHead() const;
      bool isTail() const;
      bool isFloating() const;

      void addPredecessor(const node&);
      void addSuccessor(const node&);


    private:
      const std::shared_ptr<T> _data;
      //Both sets include only immediately-adjacent nodes.
      std::unordered_set<node&> _predecessors;
      std::unordered_set<node&> _successors;
    };

    //Private methods
    node& getPosition(const T&) const;

    //Private data members

    // The set of all nodes in the graph.
    std::unordered_set<node&> _nodes;
    //Used to match an external T to the private node that contains it.
    std::unordered_map<T&, node&> _nodeRegistry;
    //_heads and _tails will always be subsets of _nodes
    std::unordered_set<node> _heads;
    std::unordered_set<node> _tails;

  };
}
