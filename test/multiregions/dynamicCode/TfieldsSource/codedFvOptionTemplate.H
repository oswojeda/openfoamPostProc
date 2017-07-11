/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2013-2014 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Description
    Template for use with dynamic code generation of a source.
    The hook functions take the following arguments:

    codeCorrect
    (
        GeometricField<Type, fvPatchField, volMesh>& fld
    )

    codeAddSup
    (
        fvMatrix<Type}>& eqn,
        const label fieldI
    )

    setValue
    (
         fvMatrix<Type}>& eqn,
        const label fieldI
    )

    where :
        fld is the field in fieldNames
        eqn is the fvMatrix

    energySource
    {
        type            scalarCodedSource;

        active          true;
        selectionMode   all;

        scalarCodedSourceCoeffs
        {
            fieldNames      (h);
            redirectType    sourceTime;

            codeInclude
            #{

            #};

            codeCorrect
            #{
                Pout<< "**codeCorrect**" << endl;
            #};

            codeAddSup
            #{
                const Time& time = mesh().time();
                const scalarField& V = mesh_.V();
                scalarField& heSource = eqn.source();
                heSource -= 0.1*sqr(time.value())*V;
            #};

            codeSetValue
            #{
                Pout<< "**codeSetValue**" << endl;
            #};

            // Dummy entry. Make dependent on above to trigger recompilation
            code
            #{
                #line 35 "/home/oswojeda/OpenFOAM/oswojeda-v1606+/run/p2moreolessorg/system/unShaded/fvOptions.TfieldsSource.scalarCodedSourceCoeffs"
#include "fvCFD.H"
                #line 45 "/home/oswojeda/OpenFOAM/oswojeda-v1606+/run/p2moreolessorg/system/unShaded/fvOptions.TfieldsSource.scalarCodedSourceCoeffs"

                #line 49 "/home/oswojeda/OpenFOAM/oswojeda-v1606+/run/p2moreolessorg/system/unShaded/fvOptions.TfieldsSource.scalarCodedSourceCoeffs"
const scalarField& T = mesh_.lookupObject<volScalarField>("T");
          const scalarField& T0 = mesh_.lookupObject<volScalarField>("T").oldTime();
          scalarField& hSource = eqn.source();
          hSource -= (1000 + 0.00008 * pow(T0,3) - 0.00012 * pow(T0,2) * T) * mesh_.V();
          //eqn += fvm::SuSp((1000 + 0.00008 * pow(T0,3) - 0.00012 * pow(T0,2) * T) * mesh_.V(),phi);
                #line 58 "/home/oswojeda/OpenFOAM/oswojeda-v1606+/run/p2moreolessorg/system/unShaded/fvOptions.TfieldsSource.scalarCodedSourceCoeffs"

            #};
        }

        sourceTimeCoeffs
        {
            // Dummy entry
        }
    }

SourceFiles
    codedFvOptionTemplate.C

\*---------------------------------------------------------------------------*/

#ifndef codedFvOptionTemplate_H
#define codedFvOptionTemplate_H

#include "fvOption.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace fv
{

/*---------------------------------------------------------------------------*\
                         A templated CodedFvOption
\*---------------------------------------------------------------------------*/

class TfieldsSourceFvOptionscalarSource
:
    public option
{
public:

    //- Information about the SHA1 of the code itself
    static const char* const SHA1sum;

    //- Runtime type information
    TypeName("TfieldsSource");


    // Constructors

        //- Construct from patch and internal field
        TfieldsSourceFvOptionscalarSource
        (
            const word& name,
            const word& modelType,
            const dictionary& dict,
            const fvMesh& mesh
        );

    //- Destructor
    virtual ~TfieldsSourceFvOptionscalarSource();


    // Member functions

            //- Correct field
            virtual void correct
            (
                GeometricField<scalar, fvPatchField, volMesh>&
            );

            //- Explicit and implicit matrix contributions
            virtual void addSup
            (
                fvMatrix<scalar>& eqn,
                const label fieldI
            );

            //- Explicit and implicit matrix contributions for compressible
            //  equations
            virtual void addSup
            (
                const volScalarField& rho,
                fvMatrix<scalar>& eqn,
                const label fieldI
            );

            //- Set value
            virtual void setValue
            (
                fvMatrix<scalar>& eqn,
                const label fieldI
            );
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

} // End namespace fv

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //

