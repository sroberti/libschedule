

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
    Each should have a name expressed as a string, to act as a handle to the node
    even before it has been created.  Upon a change of state, Nodes will notify
    all succeeding nodes of the update.

    Edge:  A set of exactly two nodes, with one explicitly and constantly defined as
    the predecessor, and the other defined as the successor.

    Head:  A maximal element of the poset.  In other words, a Node that is not
    preceded by any other Node.

    Tail:  A minimal element of the poset.  In other words, a Node that is not
    succeeded by any other Node.

    Floating:  A floating Node is both a Head and a Tail.



   */
}
