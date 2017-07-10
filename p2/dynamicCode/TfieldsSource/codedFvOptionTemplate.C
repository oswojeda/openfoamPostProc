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

\*---------------------------------------------------------------------------*/

#include "codedFvOptionTemplate.H"
#include "addToRunTimeSelectionTable.H"
#include "fvPatchFieldMapper.H"
#include "volFields.H"
#include "surfaceFields.H"
#include "unitConversion.H"
#include "fvMatrix.H"

//{{{ begin codeInclude
#line 35 "/home/oswojeda/OpenFOAM/oswojeda-v1606+/run/p2moreolessorg/system/unShaded/fvOptions.TfieldsSource.scalarCodedSourceCoeffs"
#include "fvCFD.H"
//}}} end codeInclude


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace fv
{

// * * * * * * * * * * * * * * * Local Functions * * * * * * * * * * * * * * //

//{{{ begin localCode

//}}} end localCode


// * * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * //

extern "C"
{
    // dynamicCode:
    // SHA1 = 52a6826444ad193d4b84f2777f50ba8273c04127
    //
    // unique function name that can be checked if the correct library version
    // has been loaded
    void TfieldsSource_52a6826444ad193d4b84f2777f50ba8273c04127(bool load)
    {
        if (load)
        {
            // code that can be explicitly executed after loading
        }
        else
        {
            // code that can be explicitly executed before unloading
        }
    }
}

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

//makeRemovablePatchTypeField
//(
//    fvPatch,
//    TfieldsSourceFvOptionscalarSource
//);
defineTypeNameAndDebug(TfieldsSourceFvOptionscalarSource, 0);
addRemovableToRunTimeSelectionTable
(
    option,
    TfieldsSourceFvOptionscalarSource,
    dictionary
);


const char* const TfieldsSourceFvOptionscalarSource::SHA1sum =
    "52a6826444ad193d4b84f2777f50ba8273c04127";


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

TfieldsSourceFvOptionscalarSource::
TfieldsSourceFvOptionscalarSource
(
    const word& name,
    const word& modelType,
    const dictionary& dict,
    const fvMesh& mesh
)
:
    option(name, modelType, dict, mesh)
{
    if (false)
    {
        Info<<"construct TfieldsSource sha1: 52a6826444ad193d4b84f2777f50ba8273c04127"
            " from components\n";
    }
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

TfieldsSourceFvOptionscalarSource::
~TfieldsSourceFvOptionscalarSource()
{
    if (false)
    {
        Info<<"destroy TfieldsSource sha1: 52a6826444ad193d4b84f2777f50ba8273c04127\n";
    }
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void TfieldsSourceFvOptionscalarSource::correct
(
    GeometricField<scalar, fvPatchField, volMesh>& fld
)
{
    if (false)
    {
        Info<<"TfieldsSourceFvOptionscalarSource::correct()\n";
    }

//{{{ begin code
    #line 45 "/home/oswojeda/OpenFOAM/oswojeda-v1606+/run/p2moreolessorg/system/unShaded/fvOptions.TfieldsSource.scalarCodedSourceCoeffs"

//}}} end code
}


void TfieldsSourceFvOptionscalarSource::addSup
(
    fvMatrix<scalar>& eqn,
    const label fieldI
)
{
    if (false)
    {
        Info<<"TfieldsSourceFvOptionscalarSource::addSup()\n";
    }

//{{{ begin code
    #line 49 "/home/oswojeda/OpenFOAM/oswojeda-v1606+/run/p2moreolessorg/system/unShaded/fvOptions.TfieldsSource.scalarCodedSourceCoeffs"
const scalarField& T = mesh_.lookupObject<volScalarField>("T");
          const scalarField& T0 = mesh_.lookupObject<volScalarField>("T").oldTime();
          scalarField& hSource = eqn.source();
          hSource -= (1000 + 0.00008 * pow(T0,3) - 0.00012 * pow(T0,2) * T) * mesh_.V();
          //eqn += fvm::SuSp((1000 + 0.00008 * pow(T0,3) - 0.00012 * pow(T0,2) * T) * mesh_.V(),phi);
//}}} end code
}


void TfieldsSourceFvOptionscalarSource::addSup
(
    const volScalarField& rho,
    fvMatrix<scalar>& eqn,
    const label fieldI
)
{
    if (false)
    {
        Info<<"TfieldsSourceFvOptionscalarSource::addSup()\n";
    }

//{{{ begin code
    #line 49 "/home/oswojeda/OpenFOAM/oswojeda-v1606+/run/p2moreolessorg/system/unShaded/fvOptions.TfieldsSource.scalarCodedSourceCoeffs"
const scalarField& T = mesh_.lookupObject<volScalarField>("T");
          const scalarField& T0 = mesh_.lookupObject<volScalarField>("T").oldTime();
          scalarField& hSource = eqn.source();
          hSource -= (1000 + 0.00008 * pow(T0,3) - 0.00012 * pow(T0,2) * T) * mesh_.V();
          //eqn += fvm::SuSp((1000 + 0.00008 * pow(T0,3) - 0.00012 * pow(T0,2) * T) * mesh_.V(),phi);
//}}} end code
}


void TfieldsSourceFvOptionscalarSource::setValue
(
    fvMatrix<scalar>& eqn,
    const label fieldI
)
{
    if (false)
    {
        Info<<"TfieldsSourceFvOptionscalarSource::setValue()\n";
    }

//{{{ begin code
    #line 58 "/home/oswojeda/OpenFOAM/oswojeda-v1606+/run/p2moreolessorg/system/unShaded/fvOptions.TfieldsSource.scalarCodedSourceCoeffs"

//}}} end code
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

} // End namespace fv
// ************************************************************************* //

