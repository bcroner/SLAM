#ifndef SAT_ENCODER_HPP
#define SAT_ENCODER_HPP

#include <vector>
#include <string>

// Represents a raw boolean literal in standard CNF formatting (variable ID, sign)
struct SatLiteral {
    int variable_id; // Positive integer index
    bool is_negated; // True if negated (-x), False if affirmative (+x)
};

// A unique clause constraint mapping a set of matching conditions
struct SatClause {
    std::vector<SatLiteral> literals;
};

class SatEncoder {
private:
    int next_variable_id;
    std::vector<SatClause> compiled_cnf_formula;

public:
    SatEncoder() : next_variable_id(1) {}
    ~SatEncoder() = default;

    // Generates a unique, non-zero Boolean variable ID for a matrix coordinate
    int AllocateVariable(size_t row_m, size_t col_n) {
        // Map 2D matrix coordinate topology to a linear variable space
        int allocated_id = next_variable_id;
        next_variable_id++;
        return allocated_id;
    }

    // Appends a single validation clause to the constraint matrix
    void AddClauseConstraint(const SatClause& clause) {
        if (!clause.literals.empty()) {
            compiled_cnf_formula.push_back(clause);
        }
    }

    // Returns the full logical system ready for execution
    const std::vector<SatClause>& GetFormula() const {
        return compiled_cnf_formula;
    }

    // Resets the constraint tracking structures
    void ClearFormula() {
        compiled_cnf_formula.clear();
        next_variable_id = 1;
    }
};

#endif // SAT_ENCODER_HPP
